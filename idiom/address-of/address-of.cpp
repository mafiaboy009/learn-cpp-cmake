/*
 * Find address of a object of a class that has an overloaded unary ampersand (&) operator.
 *
 */

#include <iostream>

using namespace std;

namespace learncpp{
    template <class T>
        T* addressof(T& v)
        {
            return reinterpret_cast<T*>( 
                    &const_cast<char&>( 
                        reinterpret_cast<const volatile char &>(v)
                        ) 
                    );
        }
}

struct nonaddressable
{
    typedef double useless_type;
    useless_type operator&() const{
        return 2.0;
    }
};

int main(void)
{
    nonaddressable na;
    double b = &na;
    //nonaddressable * naptr = &na; // Compiler error here.
    nonaddressable *naptr = addressof(na); // No more compiler error.
    nonaddressable *naptr1 = learncpp::addressof(na); // No more compiler error.

    cout << b << '\n';
    cout << naptr << '\n';
    cout << naptr1 << '\n';

    return 0;
}
