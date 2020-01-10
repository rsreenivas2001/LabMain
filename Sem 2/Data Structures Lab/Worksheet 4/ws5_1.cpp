#include<iostream>
using namespace std;
class stack
{
    int stk[100];
    int top;
    public:
    stack()
    {
        top=-1;
    }
    void push(int,int);
    int pop(void);
    void disp_bottom(int);
    void disp_top(int);
    void count();
};
void stack::push(int ele,int size)
{
    if(top==size)
    cout<<"Stack overflow!!";
    else
    {
        top++;
        stk[top]=ele;
    }
}
int stack::pop()
{
    int elem;
    if(top==-1)
    cout<<"Stack Underflow!!";
    else
    {
        elem=stk[top];
        top--;
    }
    return elem;
}
void stack::disp_bottom(int size)
{
    stack temp;
    int val;
    while(top!=-1)
    {
    val=pop();
    temp.push(val,size);
    }
    cout<<"The Elements from the bottom of the stack is : \n\n";
    if(top==-1)
    {
        val=temp.pop();
        cout<<val<<endl;
        push(val,size);
    }
}
void stack::disp_top(int size)
{
    stack temp;
    int val;
    cout<<"The Elements from the top of the stack is : \n\n";
    while(top!=-1)
    {
    val=pop();
    cout<<val<<endl;
    temp.push(val,size);
    }
    if(top==-1)
    {
        val=temp.pop();
        push(val,size);
    }
}
void stack::count()
{
    cout<<"The number of elements in the stack are "<<top+1;
}