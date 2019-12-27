//
//  main.cpp
//  FractionClass
//
//  Created by Marcus Jian on 2019/12/27.
//  Copyright © 2019 Marcus Jian. All rights reserved.
//

#include <iostream>

using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        return gcd(b%a, a);
    }
}
 

class Fraction
{
public:
    Fraction():Fraction(0,1)
    {}
    
    Fraction(int num, int denom)
    {
        numerator = num;
        denominator =denom;
        simplify();
    }
    Fraction Add(Fraction frac) const;
    Fraction Subtract(Fraction frac) const;
    Fraction Multiply(Fraction frac) const;
    Fraction Divide(Fraction frac) const;
    void Compare(Fraction frac_a, Fraction frac_b) const;
    void Print() const;
    
    
    static const Fraction half;
    static const Fraction third;
    static const Fraction quarter;
    static const Fraction fifth;

    
    inline int GetNumerator() const{return numerator;};
    inline int GetDenominator() const {return denominator;};
private:
     int numerator;
     int denominator;
     int divisor;
     void simplify();
    
};


const Fraction Fraction::half(1,2);
const Fraction Fraction::third(1,3);
const Fraction Fraction::quarter(1,4);
const Fraction Fraction::fifth(1,5);

void Fraction::simplify()
{
    divisor = gcd(numerator,denominator);
    numerator /= divisor;
    denominator /= divisor;
}

Fraction Fraction::Add(Fraction frac) const
{
    return Fraction((numerator * frac.denominator) + (frac.numerator * denominator), (denominator * frac.denominator));

}

Fraction Fraction::Subtract(Fraction frac) const
{
    return Fraction((numerator * frac.denominator) - (frac.numerator * denominator), (denominator * frac.denominator));

}

Fraction Fraction::Multiply(Fraction frac) const
{
    return Fraction(numerator * frac.numerator, denominator * frac.denominator);
}

Fraction Fraction::Divide(Fraction frac) const
{
    return Fraction(numerator * frac.denominator, denominator * frac.numerator);
}
 
void Fraction::Print() const
{
    std::cout << numerator << "/" << denominator;
}
int main(int argc, const char * argv[]) {
    Fraction FirstFraction(1, 2), SecondFraction(2, 7), resultFraction;
    resultFraction = FirstFraction.Add(SecondFraction);
    resultFraction.Print();
    return 0;
}
