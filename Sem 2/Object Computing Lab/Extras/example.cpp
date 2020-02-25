#include<iostream>
using namespace std;

class example
{
    int x;
    int y;
    float z;
    public:
    example(){x=10;y=20;z=31.5;}
};

int main()
{
    example ex;
    int *a=(int*)&ex;
    cout<<*a;
    a=a+1;
    cout<<endl<<*a;
    a=a+1;
    cout<<endl<<*a;
}