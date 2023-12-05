#include <iostream>
#include <memory>

using namespace std;

struct destination;
struct connection;

connection connect(destination &d);
void disconnect(connection *c);

void end_connection(connection *c) {
    disconnect(c);
}

void f(destination &d) {
    // connect to the destination
    connection c = connect(d);
    // use shared_ptr to modify the delete member function
    // pass the &c to the end_connection when f is done
    // or f is end prematurely by an exception
    shared_ptr<connection> p(&c, end_connection);
}