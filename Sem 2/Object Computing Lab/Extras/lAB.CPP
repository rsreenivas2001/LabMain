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
};
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
    Point p1(10,20),p2(30,10),p3(p2);
    cout<<p1.isorigin()<<"\n";
    p1.display();
    (p1.diff(p2)).display();
    p2.diff(p1).display();

}


