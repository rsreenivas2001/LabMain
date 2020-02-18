#include<iostream>
using namespace std;

class set
{
    int length;
    int *st;
    int index;
    public:
    set()
    {
        length=10;index=0;st=new int[10];
    }
    set(int x)
    {
        length=x;
        index=0;
        st=new int[length];
    }
    void add(int x)
    {
        st[index]=x;
        index++;
    }
    void remove()
    {
        index--;
    }
    set operator&(set &s)
    {
        int i,j;
        set t;
        for(i=0;i<index;i++)
            for(j=0;j<s.index;j++)
                if(st[i]==s.st[j])
                    {
                        t.add(st[i]);
                        break;
                    }
        return t;
    }
    set operator|(set &s)
    {
        int i,j;
        set t;
        for(i=0;i<index;i++)
            for(j=0;j<s.index;j++)
                if(st[i]==s.st[j])
                    {
                        t.add(st[i]);
                        break;
                    }
        return t;
    }
    void display()
    {
        cout<<endl;
        for(int i=0;i<index;i++)
            cout<<st[i]<<" ";
    }
};

int main()
{
    set s1(3),s2(4),s3;
    s1.add(2);
    s1.add(4);
    s1.add(5);
    s1.add(6);
    s2.add(3);
    s2.add(4);
    s2.add(6);
    s1.display();
    s2.display();
    s3=s1&s2;
    s3.display();

}
