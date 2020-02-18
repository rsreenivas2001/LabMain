#include<iostream>

using namespace std;


class node
{
    public:
    int data;
    node *next;
    node *prev;
};

class list
{
    node *head;
    public:
    list()
    {
    head=NULL;
    }
    
};