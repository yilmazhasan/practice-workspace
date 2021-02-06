#include <cstddef>
#include <iostream>

using namespace std;

template<class T>
constexpr T clone(const T& t)
{
    return t;
}

template<class T>
const constexpr T& same(const T& t)
{
    return t;
}


template<class T>
constexpr void increment(T& t)
{
    t++;
}

int main()
{
	int a = 4;
    int b = clone(a); 	// b is not a
	increment(a);		// a is 5 still b is 4
    int c = same(a); 	// c is not a, c is 5 a is 5
	increment(c);		// c is 6 a is still 5

    cout << "a: " << a << " b: " << b  << " c: " << c <<endl;
 }
