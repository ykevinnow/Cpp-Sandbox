// Intent
// Reorder the data members of a plain old data (POD) type when all members are of the same type, 
// without physically reorganizing or copying the data items.

// Also Known As
// Motivation
// The need of this idiom is best motivated using Boost's Bimap.
// Boost.Bimap is a bidirectional maps library for C++. In bimap<X,Y>, values of types X and Y can both serve as keys. 
// The implementation of such a data structure can be optimized using the boost mutant idiom.

// Solution and Sample Code
// Boost mutant idiom makes use of reinterpret_cast and depends heavily on the assumption that the memory layouts of two different structures with identical data members (types and order) are interchangeable. 
// Although the C++ standard does not guarantee this property, virtually all the compilers satisfy it. 
// Moreover, the mutant idiom is standard if only POD types are used.
// The following example shows how the boost mutant idiom works.

// 这是一个trick，基本上就是改了成员名字
#include <iostream>
#include <utility>

template <class Pair>
struct Reverse
{
    typedef typename Pair::first_type second_type;
    typedef typename Pair::second_type first_type;

    second_type second;
    first_type first;
};

template <class Pair>
Reverse<Pair> & mutate(Pair & p)
{
    return reinterpret_cast<Reverse<Pair> &>(p);
}

int main(void)
{
    std::pair<double, int> p(1.34, 5);
    std::cout << "p.first = " << p.first
              << ", p.second = " << p.second << std::endl
              << "mutate(p).first = " << mutate(p).first
              << ", mutate(p).second = " << mutate(p).second << std::endl;
}
