#include <iostream>
#include <iterator>
#include <cstddef>

using std::cin,
      std::cout,
      std::endl,
      std::begin,
      std::end;

int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    // int arr2[] = {1, 3, 4, 5, 2, 5, 9};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int state_equal = true;


    // get the pointer that point to the first arr
    int *pbeg_arr = begin(arr), *pend_arr = end(arr);
    // get the pointer that point to the first arr2
    int *pbeg_arr2 = begin(arr2), *pend_arr2 = end(arr2);

    ptrdiff_t dist_arr = pend_arr - pbeg_arr;
    ptrdiff_t dist_arr2 = pend_arr2 - pbeg_arr2;

    if (dist_arr != dist_arr2)
        cout << "Both arrays are different" << endl;
    else {
        while(pbeg_arr != pend_arr)
            if(*pbeg_arr++ != *pbeg_arr2++)
                state_equal = false;


        if (state_equal)
            cout << "Both arrays are equal" << endl;
        else
            cout << "Both arrays are different" << endl;
    }
    return 0;
}