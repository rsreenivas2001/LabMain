#include<iostream>
using namespace std;
int n;
class country
{
    public:
    char name[50];
    float pop;
    float area;
    void assign();
    
}c[10];
void country::assign()
{
    cout<<"Enter name of the country : ";
    cin>>name;
    cout<<"Enter the population : ";
    cin>>pop;
    cout<<"Enter the area :";
    cin>>area;
}

void lar_area()
{
    float max1;
    int ind1;
    max1=c[0].area;
    ind1=0;
    for(int i=1;i<n;i++)
    {
        if(c[i].area>max1)
            max1=c[i].area;
            ind1=i;
    }
    cout<<"\n\nCountry "<<c[ind1].name<<" has the largest area of "<<max1;
}

void lar_pop()
{
    float max2;
    int ind2;
    max2=c[0].pop;
    ind2=0;
    for(int i=1;i<n;i++)
    {
        if(c[i].pop>max2)
            max2=c[i].pop;
            ind2=i;
    }
    cout<<"\n\nCountry "<<c[ind2].name<<" has the largest population of "<<max2;
}
    
void lar_popden()
{
    float max3;
    int ind3;
    max3=(c[0].pop/c[0].area);
    ind3=0;
    for(int i=1;i<n;i++)
    {
        if((c[i].pop/c[i].area)>max3)
            max3=(c[i].pop/c[i].area);
            ind3=i;
    }
    cout<<"\n\nCountry "<<c[ind3].name<<" has the largest population density of "<<max3;
}

int main()
{   
    cout<<"Enter number of countries";
    cin>>n;
    country c[n];
    for(int k=0;k<n;k++)
        c[k].assign();
    lar_area();
    lar_pop();
    lar_popden();
}