#include<stdio.h>
int power(int a,int b)
{
    if(b>0)
    return a*power(a,b-1);
    else
    return 1;
}
void main()
{
    int p1,p2;
    printf("\n\t ENTER TWO NUMBERS TO FIND POWER X^Y:\n");
    scanf("%d%d",&p1,&p2);
    printf("\n\t %d POWER %d IS: %d",p1,p2,power(p1,p2));
}
