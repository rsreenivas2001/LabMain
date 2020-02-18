#include<iostream>
using namespace std;

class number
{
    int x;
    public:
    number()
    {
        x=10;
    }
    void display() const
    {
        cout<<increment(x);
    }
    void increment()
    {
        x++;
    }
};

int main()
{
    number n;
    n.display();
}
