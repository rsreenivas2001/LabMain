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
    void insertbeg();
    void insertmidafter();
    void insertmidbefore();
    void insertend();
    void deletebeg();
    void deletemidafter();
    void deletemidbefore();
    void deleteend();
    void display();
};

void list::insertbeg()
{
    int val;
    node *newnode;
    newnode= new node;
    cout<<"\nEnter a element to insert : ";
    cin>>val;
    if(head!=NULL)
    {
    newnode->data=val;
    newnode->next=head;
    newnode->prev=NULL;
    head->prev=newnode;
    head=newnode;
    }
    else if(head==NULL)
    {
    newnode->data=val;
    newnode->next=NULL;
    newnode->prev=NULL;
    head=newnode;
    }
}

void list::insertmidafter()
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
            newnode->prev=NULL;
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
        newnode->prev=t;
        (t->next)->prev=newnode;
        t->next=newnode;
        }
    }
}

void list::insertmidbefore()
{
    int val,val1,flag=0;
    node *newnode;
    newnode= new node;
    cout<<"\nEnter a element to insert : ";
    cin>>val;
    cout<<"\nEnter a element before which to be inserted : ";
    cin>>val1;

    if(head==NULL)
        {
            newnode->data=val;
            newnode->next=head;
            newnode->prev=NULL;
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
        t=t->prev;
        newnode->data=val;
        newnode->next=t->next;
        newnode->prev=t;
        (t->next)->prev=newnode;
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
            newnode->prev=NULL;
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
    newnode->prev=t;
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
        (b->next)->prev=NULL;
        head=head->next;
        delete b;
    }
}

void list::deletemidafter()
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
    r->prev=t;
    delete r;
    }
    }
}

void list::deletemidbefore()
{
    int val1,flag=0;
    cout<<"\nEnter a element before which to be deleted : ";
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
    t=t->prev;
    node* r;
    r=new node;
    r=t->next;
    t->next=r->next;
    r->prev=t;
    delete r;
    }
    }
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

void list::display()
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
    cout<<"\n\nHEAD";
    while(t!=NULL)
    {
        cout<<"-->"<<t->data;
        t=t->next;
    }
    cout<<"-->NULL\n\n";
    }
}

int main()
{
    char yn;
    int ch;
    list l;
        do
        {
        cout<<"Choose an option : ";
        cout<<"\n 1. Insert Beginning ";
        cout<<"\n 2. Insert Middle(After) ";
        cout<<"\n 3. Insert Middle(Before) ";
        cout<<"\n 4. Insert End";
        cout<<"\n 5. Delete Beginning ";
        cout<<"\n 6. Delete Middle(After) ";
        cout<<"\n 7. Delete Middle(Before) ";
        cout<<"\n 8. Delete End";
        cout<<"\nYour choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
                l.insertbeg();
                l.display();
                break;
        case 2:
                l.insertmidafter();
                l.display();
                break;
        case 3:
                l.insertmidbefore();
                l.display();
                break;
        case 4:
                l.insertend();
                l.display();
                break;
        case 5:
                l.deletebeg();
                l.display();
                break;
        case 6:
                l.deletemidafter();
                l.display();
                break;
        case 7:
                l.deletemidbefore();
                l.display();
                break;
        case 8:
                l.deleteend();
                l.display();
                break;

        default:
                cout<<"Choice Invalid!!\n\n ";
        }
        cout<<"\n\nDo you wish to continue (y/n) : ";
        cin>>yn;
        }while(yn=='y');
}

