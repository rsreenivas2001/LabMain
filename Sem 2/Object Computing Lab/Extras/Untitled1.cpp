#include<iostream>
using namespace std;
float area(float x)
{
    return 3.14*x*x;
}
float area(float x,float y)
{
    return x*y;
}
int main()
{
    cout<<"Area of circle : "<<area(2.5);
    //cout<<"\nArea of rectangle : "<<area(5.0,4.0);
    cout<<"\n"<<sizeof(wchar_t);
}
