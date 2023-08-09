#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char *argv[]) {
    // file1 is truncated in each of these cases
    ofstream out("file1");                      // out and trunc is implicit
    ofstream out2("file1", ofstream::out);      // trunc is implicit
    ofstream out3("file1", ofstream::out | ofstream::trunc);

    // to preserve the file's contents, we must specify app mode
    ofstream app("file2", ofstream::app);       // out is implicit
    ofstream app2("file2", ofstream::out | ofstream::app); 

    ofstream out;               // no file mode is set
    out.open("scratchpad");     // mode implicitly out and trunc
    out.close();
    out.open("precious", ofstream::app);    // mode is out and app
    out.close();

    return 0;
}