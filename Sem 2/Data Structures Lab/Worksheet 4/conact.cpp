#include<iostream>
#include"s_list.h"
using namespace std;



list concatenate(list &t,list &u)
{
    list temp;
    node *t1=u.ret_head();
    node *t2=t.ret_head();
    while(t1!=NULL)
    {
        temp.insertend(t1->data);
        t1=t1->next;
    }
    while(t2!=NULL)
    {
        temp.insertend(t2->data);
        t2=t2->next;
    }
    return temp;
}
int main()
{
    list l1,l2,l3;
    l1.insertend(1);
    l1.insertend(2);
    l1.insertend(3);
    l2.insertend(4);
    l2.insertend(5);
    l2.insertend(6);
    l3=concatenate(l1,l2);
    l3.display();
    l3=concatenate(l2,l1);
    l3.display();

}