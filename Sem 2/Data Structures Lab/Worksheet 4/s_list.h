#include<iostream>
using namespace std;


class node
{
    public:
    int data;
    node *next;
}*head=NULL;

class list
{
    node *head;
   public:

    list()
    {
    head=NULL;
    }
    list(int a,int b,int c,int d)
    {
        insertend(a);
        insertend(b);
        insertend(c);
        insertend(d);
    }
    node* ret_head(){return head;}
    void insertbeg();
    void insertbeg(int);
    void insertmid();
    void insertmid(int,int);
    void insertend();
    void insertend(int);
    void deletebeg();
    void deletemid();
    void deletemid(int);
    void deleteend();
    void display();
    void swap_min_max();

};
void list::insertbeg()
{
    int val;
    node *newnode;
    newnode= new node;
    cout<<"\nEnter a element to insert : ";
    cin>>val;
    newnode->data=val;
    newnode->next=head;
    head=newnode;
}
void list::insertbeg(int val)
{

    node *newnode;
    newnode= new node;

    newnode->data=val;
    newnode->next=head;
    head=newnode;
}
void list::display()
{
    if(head==NULL)
        {
            cout<<"EMPTY!!";
        }
    node* t;
    t=new node();
    t=head;


    cout<<"\n\nHEAD";
    while(t!=NULL)
    {
        cout<<"-->"<<t->data;
        t=t->next;
    }
    cout<<"-->NULL\n\n";
}
void list::insertmid()
{
    int val,val1,flag=0;
    node *newnode;
    newnode= new node;
    cout<<"\nEnter a element to insert : ";
    cin>>val;
    cout<<"\nEnter a element after which to be inserted : ";
    cin>>val1;

    if(head==NULL)
        {
            newnode->data=val;
            newnode->next=head;
            head=newnode;
        }
    else
    {
    node* t;
    t=new node();
    t=head;
    while(t!=NULL)
    {
        if(t->data==val1)
        {
            flag=1;
            break;
        }
        t=t->next;
    }
    if(flag==1)
    {
    newnode->data=val;
    newnode->next=t->next;
    t->next=newnode;
    }
    }
}

void list::insertmid(int val,int val1)
{
    int flag=0;
    node *newnode;
    newnode= new node;


    if(head==NULL)
        {
            newnode->data=val;
            newnode->next=head;
            head=newnode;
        }
    else
    {
    node* t;
    t=new node();
    t=head;
    while(t!=NULL)
    {
        if(t->data==val1)
        {
            flag=1;
            break;
        }
        t=t->next;
    }
    if(flag==1)
    {
    newnode->data=val;
    newnode->next=t->next;
    t->next=newnode;
    }
    }
}
void list::insertend()
{

    int val;
    node *newnode;
    newnode= new node;
    cout<<"\nEnter a element to insert : ";
    cin>>val;
    if(head==NULL)
        {
            newnode->data=val;
            newnode->next=head;
            head=newnode;
        }
    else
    {
    node* t;
    t=new node();
    t=head;
    while(t->next!=NULL)
        t=t->next;
    newnode->data=val;
    newnode->next=t->next;
    t->next=newnode;
    }
}
void list::insertend(int val)
{


    node *newnode;
    newnode= new node;

    if(head==NULL)
        {
            newnode->data=val;
            newnode->next=head;
            head=newnode;
        }
    else
    {
    node* t;
    t=new node();
    t=head;
    while(t->next!=NULL)
        t=t->next;
    newnode->data=val;
    newnode->next=t->next;
    t->next=newnode;
    }
}
void list::deletebeg()
{
    if(head==NULL)
    {
        cout<<"EMPTY!!";
    }
    else
    {
        node* b;
        b=new node;
        b=head;
        head=head->next;
        delete b;
    }
}
void list::deletemid()
{
    int val1,flag=0;
    cout<<"\nEnter a element after which to be deleted : ";
    cin>>val1;
    if(head==NULL)
        {
            cout<<"EMPTY!!";
        }
    else
    {
    node* t;
    t=new node();
    t=head;
    while(t!=NULL)
    {
        if(t->data==val1)
        {
            flag=1;
            break;
        }
        t=t->next;
    }
    if(flag==1)
    {
    node* r;
    r=new node;
    r=t->next;
    t->next=r->next;
    delete r;
    }
    }
}

void list::deletemid(int val1)
{
    int flag=0;

    if(head==NULL)
        {
            cout<<"EMPTY!!";
        }
    else
    {
    node* t;
    t=new node();
    t=head;
    while(t!=NULL)
    {
        if(t->data==val1)
        {
            flag=1;
            break;
        }
        t=t->next;
    }
    if(flag==1)
    {
    node* r;
    r=new node;
    r=t->next;
    t->next=r->next;
    delete r;
    }
    }
}

void list::swap_min_max()
{
    node *max,*min,*t;
    max=head;
    min=head;
    node *pmin=NULL,*pmax=NULL,*pt=head;
    t=head;
    cout<<"working";

    while(t=NULL)
    {
        if((min->data)>(t->data))
            {
                pmin=pt;
                min=t;

            }
        if((max->data)<(t->data))
            {
                pmax=pt;
                max=t;

            }
            pt=t;
        t=t->next;
    }
    cout<<"\nworking";
    node *t1,*t2,*t3;
    cout<<"\nworking\n";
    cout<<(min->next)->data;
    cout<<(max->next)->data;

    t2=max->next;

    cout<<"\nworking";
    min=max;
    max->next=min->next;
    pmax->next=min;
    min->next=t2;

}

void list::deleteend()
{
    if(head==NULL)
        {
            cout<<"EMPTY!!";
        }
    else
    {
    node* t;
    t=new node();
    t=head;
    while((t->next)->next!=NULL)
        t=t->next;
    node* r;
    r=new node;
    r=t->next;
    t->next=NULL;
    delete r;
    }
}
