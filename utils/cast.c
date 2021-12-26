// 此间函数只适用于ascii

#include <stdio.h>
#include <assert.h>

// #define SPACE ' '
// #define UNDER_SCORE '_'

const unsigned char SPACE = ' ';
const unsigned char UNDER_SCORE = '_';

unsigned char to_lowercase(const unsigned char c) {
    return c | SPACE;
}

unsigned char to_uppercase(const unsigned char c) {
    return c & UNDER_SCORE;
}

unsigned char flip_case(const unsigned char c) {
    return c ^ SPACE;
}

int main()
{
    assert('c' == to_lowercase('C'));
    assert('C' == to_uppercase('c'));
    assert('c' == flip_case('C'));
    assert('C' == flip_case('c'));

    return 0;
}
