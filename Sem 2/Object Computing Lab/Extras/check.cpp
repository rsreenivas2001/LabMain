#include<iostream>
using namespace std;
class Point
{
    public:
    int x,y;
    Point( );
    Point(int ,int );
    Point(&Point);
    bool isorigin();
    void display();
    Point diff(Point);
    void negative();
    Point add(Point);
    void operator-();
};
Point Point::operator-()
{
    Point t;
    t.x=-x;
    t.y=-y;
    return t;
}
Point Point::operator=()
{
    Point t;
    t.x=x;
    t.y=y;
    return t;
}

Point::Point( )
{
    x=0;y=0;
}
Point::Point(int x,int y)
{
    this->x=x;
    this->y=y;
}
Point::Point(Point &P)
{
    x=P.x;
    y=P.y;
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
    Point px;
    px.x=x;
    px.y=y;
    pp.negative();
    return (px.add(pp));
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
    Point p1(10,20),p2;
    p2=-p1;
    p2.display();

}


