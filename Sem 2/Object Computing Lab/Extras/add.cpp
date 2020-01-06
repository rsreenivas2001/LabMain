#include<iostream>
using namespace std;
class numb
{
    int a;
    public:
    void assign(int x)
    {
        a=x;
    }
    void print()
    {
        cout<<a;
    }

    numb max(numb x)
    {
        numb a4;
        if(a>x.a)
        a4.a=a;
        else
        a4.a=x.a;
        return a4;
    }

};
int main()
{
    numb a1,a2,a3;
    a1.assign(10);
    a2.assign(5);
    a3=a1.max(a2);
    a3.print();
}