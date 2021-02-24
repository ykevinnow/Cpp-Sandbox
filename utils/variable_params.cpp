#include <iostream>

// 最关键的是这个
bool isRegular(){
    return true;
}

bool isRegular(const char c) {
    return ((c != '*') && (c != '.'));
}

// template <typename T>
// bool isRegular(const T& t) {
//     return isRegular(t);
// }

template <typename T, typename... Args>
bool isRegular(const T& t, const Args&... args) {
    return (isRegular(t) && isRegular(args...));
}

int main()
{
    std::cout << isRegular('c', 'd', 'e');
}