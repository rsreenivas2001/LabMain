#include"Rational.h"
class Set
{
    private:
        Rational q[50];
        int count;
    public:
        Set()
        {

            count=-1;
        }
        Set union1(Set a);
        Set intersection(Set b);
        void remove(Rational x);
        void insert(Rational y);
        void duplicate_removal(Set c);
        void duplicate_removal();
        void display_set();
};
Set Set::union1(Set a)
{
    Set temp1;
    duplicate_removal();
    a.duplicate_removal();
    for(int i=0;i<=count;i++)
        temp1.insert(q[i]);
    temp1.display_set();
    cout<<endl;
    for(int i=0;i<=a.count;i++)

        temp1.insert(a.q[i]);
    temp1.display_set();
    cout<<endl;
    temp1.duplicate_removal();
    temp1.display_set();
    cout<<endl;
    return temp1;

}

Set Set::intersection(Set b)
{
    Set temp;
    
    duplicate_removal();
    display_set();
    cout<<endl;
    b.duplicate_removal();
    b.display_set();
    cout<<endl;
    for(int i=0;i<=count;i++)
        for(int j=0;j<=b.count;j++)
        {
            if(q[i].check(b.q[j]))
                temp.insert(q[i]);
        }
    temp.display_set();
    cout<<endl;
    temp.duplicate_removal();
    temp.display_set();
    cout<<endl;
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

void Set::duplicate_removal()
{
    for(int i=0;i<=count;i++)
        for(int j=0;j<=count;j++)
        {
            if(i!=j)
            if(q[i].check(q[j]))
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