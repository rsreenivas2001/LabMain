
#include<stdlib.h>
#include"Set.h"
#include<iostream>
using namespace std;
Set Set::union1(Set a)
{
    Set temp1;
    a.duplicate_removal(a);
    for(int i=0;i<=count;i++)
        temp1.insert(q[i]);
    for(int i=0;i<=a.count;i++)
        temp1.insert(a.q[i]);
    return temp1;

}

Set Set::intersection(Set b)
{
    Set temp;
    for(int i=0;i<=count;i++)
        for(int j=0;j<=b.count;j++)
        {
            if(q[i].check(b.q[j]))
                temp.insert(q[i]);
        }
    temp.duplicate_removal(temp);
    return temp;
}

void Set::duplicate_removal(Set c)
{
    for(int i=0;i<=count;i++)
        for(int j=0;j<=c.count;j++)
        {
            if(q[i].check(c.q[j]))
                remove(q[i]);
        }
}

void Set::insert(Rational y)
{
    if(count+1==50)
        {
        cout<<"Set-full!!";
        exit(0);
        }
    else
    {
        count+=1;
        q[count]=y;
        display_set();
    }
}
void Set::remove(Rational x)
{
    if(count==-1)
        {
        cout<<"Set-Empty!!";
        exit(0);
        }
    else
    {
        for(int i=0;i<=count;i++)
        {
            if(q[i].check(x))
            {
                for(int j=i;j<count;j++)
                    q[i]=q[i+1];
                count-=1;
            }
        }
    }
}
void Set::display_set()
{
    for(int i=0;i<=count;i++)
        q[i].disp();
}


















