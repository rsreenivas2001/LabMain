#include<stdio.h>
int fact(int x)
{
    if(x==0)
        return 1;
    else
        return fact(x-1)*x;
}
void main()
{
    int n,f;
    printf("Enter a number to find the factorial ");
    scanf("%d",&n);
    f=fact(n);
    printf("The factorial of the given number is %d",f);
}
