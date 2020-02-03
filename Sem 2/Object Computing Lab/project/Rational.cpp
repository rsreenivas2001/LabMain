#include"Rational.h"

#include<iostream>
using namespace std;


bool Rational::check(Rational z)
{
    if(m==z.m&&n==z.n)
    return true;
    else
    return false;
}
void Rational::disp()
{
    cout<<m<<"/"<<n<<"\t";
}
