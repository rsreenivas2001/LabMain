#include<iostream>
#include<string.h>

using namespace std;
class Point
{
       int x,y;
       char *name;
    public:

    Point( );
    Point(int ,int ,char *);
    Point(Point&);
    bool isorigin();
    void display();
    Point diff(Point);
    void negative();
    Point add(Point);
    Point operator-();
    Point operator+(Point&);
    Point operator-(Point&);
    friend ostream& operator<<(ostream &out,const Point &p);
    friend istream& operator>>(istream &in,Point &p);


};

ostream& operator<<(ostream &out,const Point &p)
{
    out<<"\nx="<<p.x;
    out<<"\ny="<<p.y;
    out<<"\nName="<<p.name;
    return out;
}
istream& operator>>(istream &in,Point &p)
{
    in.ignore();

    cout<<"\nEnter x : ";
    in>>p.x;
    cout<<"\nEnter y : ";
    in>>p.y;
    cout<<"\nEnter name : ";
    in>>p.name;
    return in;
}
Point Point::operator-()
{


    Point t;
    t.x=-x;
    t.y=-y;
    return t;
}

Point Point::operator+(Point&p)
{
    Point t;
    t.x=x+p.x;
    t.y=y+p.y;
    return t;
}
Point Point::operator-(Point&p)
{
    Point t;
    t.x=x-p.x;
    t.y=y-p.y;
    return t;
}
Point::Point( )
{
    x=0;y=0;
    name=NULL;
}
Point::Point(int x,int y,char name[])
{
    this->x=x;
    this->y=y;
    this->name=name;
}
Point::Point(Point &P)
{
    x=P.x;
    y=P.y;
    strcpy(name,P.name);
}
bool Point::isorigin()
{
    if(x==0&&y==0)
    return true;
    else
    return false;
}
void Point::display()
{
    cout<<"x="<<x<<"\n";
    cout<<"y="<<y<<"\n";
}
void Point::negative()
{
    x=-x;
    y=-y;
}
Point Point::diff(Point pp)
{
    Point pa;
    pa.x=x-pp.x;
    pa.y=y-pp.y;
    return pa;
}
Point Point::add(Point pp)
{
    Point pa;
    pa.x=x+pp.x;
    pa.y=y+pp.y;
    return pa;
}
int main()
{
    Point p1,p2,p3,p4;
    cin>>p1;
    cin>>p2;
    p3=p1+p2;
    cout<<p3;


}


