#include <iostream>

using namespace std;

class A
{
public:
int i, j;
A()
                {
                    i=10;
                }
A(int j=3)
                {i = j;}

};

int main()
{
        A a = 4;
cout<<a.i<<"\n";
cout<<a.j;
return 0;

}
