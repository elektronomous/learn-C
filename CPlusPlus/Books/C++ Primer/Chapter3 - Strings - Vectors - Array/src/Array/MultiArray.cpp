#include <iostream>

using std::cout,
    std::cin,
    std::endl;

int main(void)
{
    // array of size 2; each element is an array of ints of size 4
    int arr1[2][4] = {
        {1, 2, 3, 4},
        {6, 4, 3, 5}};
    /*
    [0] => [0][1][2][3]
    [1] => [0][1][2][3]
    */

    // array of size 2;
    // each element of size 2 is an array of ints of size 3
    // each element of size 3 is an array of ints of size 5
    int arr2[2][3][5] = {
        {{1, 2, 3, 4, 5},
         {1, 2, 3, 4, 5},
         {1, 2, 3, 4, 5}},
        {{1, 2, 3, 4, 5},
         {1, 2, 3, 4, 5},
         {1, 2, 3, 4, 5}},
    };
    /*
    [0] => [0] [1] [2]
           \/  \/  \/
           |   |   |
           |   |   |
           |   |   |
           |   |   |__[0][1][2][3][4]
           |   |__[0][1][2][3][4]
           |___ [0][1][2][3][4]

    [1] => [0] [1] [2]
           \/  \/  \/
           |   |   |
           |   |   |
           |   |   |
           |   |   |__[0][1][2][3][4]
           |   |__[0][1][2][3][4]
           |___ [0][1][2][3][4]
    */

    std::cout << arr1[0][1] << std::endl;
    std::cout << arr2[0][0][1] << std::endl;

    // row is the first dimension of two-dimensional array
    // coloumn is the second dimension of two-dimensional array
    int(&row)[4] = arr1[0]; // get the first row

    // show the value of the row
    for (size_t i = 0; i < 4; i++)
        std::cout << row[i] << " ";
    std::cout << std::endl;

    // initialize multi dimensional array using for-loop
    constexpr size_t Row = 3, col = 4;
    int ia[Row][col];

    // for each row
    for (size_t r = 0; r < Row; r++)
        // for each column in row
        for (size_t c = 0; c < col; c++)
            ia[r][c] = r * col + c;

    for (size_t r = 0; r < Row; r++)
    {
        // for each column in row
        for (size_t c = 0; c < col; c++)
            std::cout << ia[r][c] << " ";
        std::cout << std::endl; // each row get new line
    }

    // size_t counter = 0;
    // int (*p)[4] = ia;

    // the alternative way to show up
    std::cout << "Alternative way: ";
    for(int (&rows)[4] : ia) {
        for (int &cols : rows) {
            std::cout << cols << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}