#include<stdio.h>
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
void main()
{
    int a,b,g;
    printf("Enter two numbers ");
    scanf("%d %d",&a,&b);
    g=gcd(a,b);
    printf("The GCD of given two numbers is %d",g);
}
