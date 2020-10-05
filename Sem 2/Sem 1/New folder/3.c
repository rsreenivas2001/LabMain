#include<stdio.h>
int recursive(int x)
{
    if(x==0)
        return 1;
    else
        return (recursive(x-1)*x)+x;
}
void main()
{
    int ans;
    ans=recursive(4);
    printf("The calculated value using function for 4 is %d",ans);
}
