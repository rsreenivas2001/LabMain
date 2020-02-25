#include<iostream>
#include"s_list.h"
using namespace std;

int main()
{
    int k,i;
    list l1;
    cout<<"Enter the number of Inputs : ";
    cin>>k;
    for(i=0;i<k;i++)
        l1.insertbeg();
    l1.display();
    cout<<"After swapping the Nodes: \n";
    l1.swap_min_max();
    
    
    return 0;
}
