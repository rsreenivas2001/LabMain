#include <iostream>


using namespace std;



unsigned int DivBy5(unsigned int n)
{
    if(n % 5 == 0)
        return 1 + DivBy5(n / 5);
    else
        return  0;
}

int MinNum(int present, int sum, int value)
{
    if (sum >= value)
        return present - 1;
    else
    {
        sum += DivBy5(present);
        return MinNum(present + 1, sum, value);
    }
}

int main()
{
    int val;
    //cout<<DivBy5(35);
    cout << "Please enter the value: ";
    cin >> val;
    int ans = MinNum(1, 0, val);
    cout << "The answer is " << ans << endl;
}