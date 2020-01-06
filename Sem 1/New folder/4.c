#include<stdio.h>
int sum(int x)
{
    if(x==0)
        return 0;
    else
        return sum(x-1)+x;
}
void main()
{
    int n,s;
    printf("Enter the number : ");
    scanf("%d",&n);
    s=sum(n);
    printf("The sum is %d",s);
}
