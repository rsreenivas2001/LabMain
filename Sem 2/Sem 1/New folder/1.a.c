#include<stdio.h>
void numpalindrome(int a)
{
    int r=0,x;
    x=a;
    while(a!=0)
    {
        r=r*10;
        r=r+a%10;
        a=a/10;
    }
    if(r==x)
        printf("The number is a palindrome");
    else
        printf("The number is not a palindrome");
}
void main()
{
    int z;
    printf("Enter a number ");
    scanf("%d",&z);
    numpalindrome(z);
}
