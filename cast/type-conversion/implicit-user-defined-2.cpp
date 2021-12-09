/*
 * Implicit type conversion is useful when creating 
 * numerical type of classes, such as rational class
 */

#include <iostream>

using namespace std;

class Rational{
    public:
        Rational(int numerator=0, int denominator=1):
            m_numerator{numerator},
            m_denominator{denominator}
        {}
        int m_numerator;
        int m_denominator;

        /*
        const Rational operator*( const Rational &rhs){
            return Rational( m_numerator*rhs.m_numerator, m_denominator*rhs.m_denominator);
        }
        
        operator int() const { return m_numerator/m_denominator; }
        */
};

const Rational operator*( const Rational& op1, const Rational& op2 ){
    return Rational( op1.m_numerator*op2.m_numerator, op1.m_denominator*op2.m_denominator );
}

int main(){

    Rational r1{23, 2};
    Rational r2 = r1 * Rational{2, 2}; // line# 16 or #20; compiler confused; SOLUTION: line# 27
    Rational r3 = r1 * 2; // line# 16 or #20; compiler confused; SOLUTION: line# 27
    Rational r4 = 3 * r1; // line# 20; SOLUTION: line# 27
    Rational r5{23, 0};

    auto printRational = [](Rational& r) noexcept {
        cout << r.m_numerator << " " << r.m_denominator << '\n';
    };

    printRational( r1 );
    printRational( r2 );
    printRational( r3 );
    printRational( r4 );
    printRational( r5 );

    return 0;
}
