/* Compile the following program to sere what happens when you
   forget the semicolon after a class definition. Remember the mesage for
   the future reference:
*/

struct Foo {};
// error: expected ';' after struct definition

int main(void) {
    return 0;
}