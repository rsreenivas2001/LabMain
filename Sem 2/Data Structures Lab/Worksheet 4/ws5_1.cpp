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
int main()
{
        stack ss;
        int sizee,ch,eleme;
        cout<<"Enter the size of stack";
        cin>>sizee;
        char yn;
        do
        {
        cout<<"Choose an option : ";
        cout<<" 1. Push ";
        cout<<"\n 2. Pop ";
        cout<<"\n 3. Display from Bottom";
        cout<<"\n 4. Display from Top ";
        cout<<"\n 5. Display number of Elememts \n Your choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
                cout<<"Enter element to push : ";
                cin>>eleme;
                ss.push(eleme,sizee);
                break;
        case 2:
                ss.pop();
                break;
        case 3:
                ss.disp_bottom(sizee);
                break;
        case 4:
                ss.disp_top(sizee);
                break;
        case 5:
                ss.count();
                break;
        default:
                cout<<"Choice Invalid!!\n\n ";
        }
        cout<<"\n\nDo you wish to continue (y/n) : ";
        cin>>yn;
        }while(yn=='y');
}

