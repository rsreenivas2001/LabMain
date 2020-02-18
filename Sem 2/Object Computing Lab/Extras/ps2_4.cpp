#include<iostream>
using namespace std;

class MyString
{
    char *str;
    int len;
public:
    MyString()
    {
        cout<<"\n\nEnter the size of string : ";
        cin>>len;
        str=new char[len];
    }
    MyString(int l)
    {
        len=l;
        str=new char[len];
    }
    MyString(MyString &x)
    {
        str=x.str;
        len=x.len;
    }
    bool operator==(MyString);
    MyString operator+(MyString);
    void operator=(MyString);
    MyString operator++();
    MyString operator--();
}

 bool MyString::operator==(MyString x)
{
    int i;
    if(len==x.len)
    {
    for(i=0;i<len;i++)
        if(str[i}!=x.str[i])
        return false;
    }
    else
        return false;
    return true;
}
MyString operator+(MyString x)
{
    int i,length;
    length=len+x.len;
    MyString temp(length);
    for(i=0;i<len;i++)
        temp[i]=str[i];
    for(j=i;j<x.len;j++)
        temp[j]=x.str[j];
    return temp;
}


int main()
{
    MyString s1,s2;

}
