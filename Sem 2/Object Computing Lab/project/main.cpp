
#include<iostream>
using namespace std;

#include"Set.h"
int main()
{
    int ch,num,m1,n1;
    Set s1,s2,s3;
    char xy='y';
    cout<<"\n\nEnter 'm' and 'n' for first element of Set 1 : \n\n"; //first element for set 1
    cin>>m1>>n1;
    Rational r1(m1,n1);
        s1.insert(r1);
    cout<<"\n\nEnter 'm' and 'n' for first element of Set 2 : \n\n";
    cin>>m1>>n1;
    Rational r2(m1,n1);

    s2.insert(r2);
     while(xy=='y'||xy=='Y')
     {

    cout<<"\n\nEnter the option to perform the following operations : \n\n";
    cout<<"1 .Union\n2.Intersection\n3.Insert\n4.Remove\n5.Remove Duplicate\n";
    cout<<"Enter choice : ";
    cin>>ch;


        switch(ch)  //A menu for given options
    {
        case 1:s3=s1.union1(s2);
               s3.display_set();
               break;
        case 2:s3=s1.intersection(s2);
               s3.display_set();
               break;
        case 3:cout<<"Enter 1 for set 1 and 2 for set 2";
               cin>>num;
               if(num==1)
               {
                   cout<<"\n\nEnter 'm' and 'n' for  the rational number : \n\n";
                   cin>>m1>>n1;
                   Rational r3(m1,n1);
                   s1.insert(r3);
               }
                if(num==2)
               {
                   cout<<"\n\nEnter 'm' and 'n' for  the rational number : \n\n";
                   cin>>m1>>n1;
                   Rational r3(m1,n1);
                   s2.insert(r3);
               }
               break;
        case 4:cout<<"Enter 1 for set 1 and 2 for set 2";
               cin>>num;
               if(num==1)
               {
                   cout<<"\n\nEnter 'm' and 'n' for the rational number : \n\n";
                   cin>>m1>>n1;
                   Rational r3(m1,n1);
                   s1.remove(r3);
                   s1.display_set();
               }
                if(num==2)
               {
                   cout<<"\n\nEnter 'm' and 'n' for  the rational number : \n\n";
                   cin>>m1>>n1;
                   Rational r3(m1,n1);
                   s2.remove(r3);
               }
               break;
        case 5:s1.duplicate_removal(s2);
               s1.display_set();
               break;

    }
    cout<<"Enter y to perform another task :";
    cin>>xy;
    }







       return 0;
}
