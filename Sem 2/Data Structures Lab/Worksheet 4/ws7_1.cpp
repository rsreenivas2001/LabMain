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



int main()
{
    char yn;
    int ch;
    list l;
        do
        {
        cout<<"Choose an option : ";
        cout<<"\n 1. Insert Beginning ";
        cout<<"\n 2. Insert Middle ";
        cout<<"\n 3. Insert End";
        cout<<"\n 4. Delete Beginning ";
        cout<<"\n 5. Delete Middle ";
        cout<<"\n 6. Delete End";
        cout<<"\nYour choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
                l.insertbeg();
                l.display();
                break;
        case 2:
                l.insertmid();
                l.display();
                break;
        case 3:
                l.insertend();
                l.display();
                break;
        case 4:
                l.deletebeg();
                l.display();
                break;
        case 5:
                l.deletemid();
                l.display();
                break;
        case 6:
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
