#include"rectangle.h"

void rect::set (float x)
{
    cout<<"Enter length";
    cin>>l;
    cout<<"Enter breadth";
    cin>>b;
}
float rect::getl()
{
    return l;
}
float rect::getb()
{
    return b;
}
float area()
{
    return l*b;
}
float perimeter()
{
    return (2*(l+b));
}
