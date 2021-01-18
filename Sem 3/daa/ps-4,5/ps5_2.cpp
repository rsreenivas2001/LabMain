#include <iostream>
#include <list>

using namespace std;

//returns max of 2 binary numbers
list<bool> maximum(list<bool> list_1, list<bool> list_2)
{
    list<bool>::iterator first = list_1.begin();
    list<bool>::iterator second = list_2.begin();
    while (first != list_1.end())
    {
        if (*first ^ *second == 0)
        {
            first++;
            second++;
        }
        else
            if(*first)
                return list_1; 
            else
                return list_2;
    }
    return list_1;
}

int main()
{
    list<list<bool>> binary;
    char check;
    int count = 0;
    int val;
    cout << "Please enter the Binary numbers " << endl;
    do
    {
        cout << "Please enter Binary Number (" << count + 1 << ") Press -1 to stop" << endl;
        list<bool> vec;
        while (true)
        {
            cin >> val;
            if (val == 1 || val == 0)
                vec.push_back(val);
            else
                break;
        }
        binary.push_back(vec);
        cout << "Do you want to add a new number ? " << endl
             << "Press y to enter a new number n to stop: ";
        cin >> check;
        count++;
    } while (check == 'y');

    list<bool> max = binary.front();
    for (auto eachList : binary)
        max = maximum(max, eachList);

    cout << "\nMax Binary Digit : " << endl;
    for(auto digit: max)
        cout << digit;
    
    return 0;
}