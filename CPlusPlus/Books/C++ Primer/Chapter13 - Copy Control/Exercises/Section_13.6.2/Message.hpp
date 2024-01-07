#include <iostream>
#include <set>

using namespace std;

class Message;

class Folder {
    public:
        // you can't add or remove temporary Message
        void addMsg(Message *);
        void addMsg(Message &);
        void remMsg(Message *);
        void remMsg(Message &);

    private:
        set<Message*> messages;
};

void Folder::addMsg(Message *m) {
    messages.insert(m);
}

void Folder::remMsg(Message *m) {
    messages.erase(m);
}

void Folder::addMsg(Message &m) {
    messages.insert(&m);
}

void Folder::remMsg(Message &m) {
    messages.erase(&m);
}

class Message {
    friend class Folder;
    friend void swap(Message&, Message&);
    public:
        // folders is implicitly initialized to the empty set
        explicit Message(const string &str = ""): contents(str) { }

        // copy control to manage pointer to this message
        Message(const Message&);                // copy constructor
        Message& operator=(const Message&);     // copy assignment
        ~Message();                             // destructor
        // 13.49.txt
        Message(Message&&);                     // move constructor
        Message& operator=(Message &&);          // move assignment

        // add/remove this message from the specified Folder's set of messages
        void save(Folder&);
        void remove(Folder&);
        // 13.36.cpp
        void addFolder(Folder*);
        void remFolder(Folder*);
    
    private:
        string contents;        // actual message text
        set<Folder*> folders;   // Folders that have this message

        // utility function that used by copy constructor, assignment and
        // destructor
        // add this Message to the Folder that point to the parameter
        void add_to_Folders(const Message&);
        // remove this Message from every Folders in folders
        void remove_from_Folders();
        // 13.6.2 update the folder pointer
        void move_Folders(Message *m);
};

void Message::save(Folder &f) {
    folders.insert(&f);     // add the given Folder to our list of Folders
    f.addMsg(this);         // add this Message to f's set of Messages
}

void Message::remove(Folder &f) {
    folders.erase(&f);      // take the given Folder out of our list of Folders
    f.remMsg(this);         // remove this message from f's set of Message
}

/* 
    if you confused by this at add_to_Folder, Note this:
        Message m1("Hello"), m2(m1)
*/
Message::Message(const Message &m):
    contents(m.contents), folders(m.folders) {
        add_to_Folders(m);  // add this Message to the Folder that point to m
    }

// add this Message to Folders that point to m
void Message::add_to_Folders(const Message &m) {
    for (Folder *f: m.folders)   // for each Folder that hold m
        f->addMsg(this);        // add this Message to that Folder
}

Message::~Message() {
    remove_from_Folders();
}

void Message::remove_from_Folders() {
    for (Folder *f: folders)
        f->remMsg(this);
}

Message& Message::operator=(const Message &rhs) {
    // handle self-assignment by removing pointers before inserting them
    remove_from_Folders();      // remove this Message from folders
    contents = rhs.contents;    // copy message from rhs
    folders = rhs.folders;      // copy folders from rhs
    add_to_Folders(rhs);         // add this Message to those folders

    return *this;
}

void swap(Message &lhs, Message &rhs) {
    using std::swap;            // not strictly needed in this case, but good habit
    // remove pointers to each Message from their (original) perspective Folder
    for (Folder *f: lhs.folders)
        f->remMsg(lhs);
    for (Folder *f: rhs.folders)
        f->remMsg(rhs);
    
    // swap the contents and Folder pointer sets
    swap(lhs.folders, rhs.folders);     // use swap(set&, set&);
    swap(lhs.contents, rhs.contents);   // use swap(string&, string&);

    // add pointers to each Message to their(new) perspective Folder
    for (Folder *f: lhs.folders)
        f->addMsg(lhs);
    for (Folder *f: rhs.folders)
        f->addMsg(rhs);
};

void Message::addFolder(Folder *f) {
    folders.insert(f);
}

void Message::remFolder(Folder *f) {
    folders.erase(f);
}

// 13.6.2 move Folder pointers from m to this Message
void Message::move_Folders(Message *m) {
    folders = std::move(m->folders);        // uses set move assignment
    for (Folder *f: folders) {      // for each Folder
        f->remMsg(m);           // remove this Message to that Folder
        f->addMsg(this);        // add this Message to that Folder
    }
    m->folders.clear();         // ensure that destroying m is harmless
}

// 13.6.2 move constructor
// 13.49.txt
Message::Message(Message &&m): 
    contents(std::move(m.contents)), folders(std::move(m.folders)) {
        move_Folders(&m);
    }

// 13.49.txt
Message& Message::operator=(Message &&rhs) {
    if (this != &rhs) {        // direct check for self-assignment
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}