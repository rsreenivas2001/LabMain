#include<stdio.h>

double power(double x,int y)
{
    if(y==0)
        return 1;
    else if(y==1)
        return x;
    else
    {
        return power(x,y-1)*x;
    }

}
void main()
{
    double x;
    int y;
    printf("Enter the number: ");
    scanf("%lf",&x);
    printf("Enter the power to be raised to: ");
    scanf("%d",&y);
    printf("The number %.2lf raised to %d is %.2lf\n",x,y,power(x,y));
}
