#include <algorithm>
#include <vector>

#include "print.hpp"
#include "size_of_array.hpp"
#include "defer.hpp"

using namespace std;

// for defer.hpp
void some_func(void) {
    FILE *file = fopen("sometext.txt", "rb");
    if (file == NULL)
        return;
    defer(fclose(file));

    defer({
        cout << "Now you can defer in C++11" << '\n';
    });
}

int main()
{
    vector<int> coll = {1, 2, 3, 5, 7, 9};
    PRINT_ELEMENTS(coll);

    int ia[6] = {9, 8, 7, 6, 5, 4};
    vector<int> iv(ia, ia + 6);

    // we got a temp variable here
    for_each(iv.begin(), iv.end(), print<int>());
    cout << '\n';

    // size of array
    int array[] = {2, 3, 4};
    cout << "size of array is: " << arraySize<int>(array) << '\n';

    // defer
    some_func();
}