#include<stdio.h>
    #include<conio.h>
    #include<stdlib.h>
    #include<conio.h>
    void main()
    {
        int a[10],i,n,d[10],power;
        float in[10];

        printf("Enter the order ofthe polynomial\n");
        scanf("%d",&n);
        for(i=n;i>=0;i--)
        {
            printf("Enter the co-efficient of x^%d:",i);
            scanf("%d",&a[i]);

        }
        printf("Given polynomial is\n");
        for(i=n;i>=0;i--)
        {
            if(power<0)
            {
                break;
            }
            if(a[i]>0)
            {
            if(i!=n)
            printf(" + ");
            }
            else if(a[i]<0)
                printf(" - ");
                else
                printf(" ");
            printf("%dx^%d",abs(a[i]),i);
        }
        //To find derivative
        for(i=n;i>=0;i--)
        d[i]=a[i]*i;
        printf("\n Derivative of the given polynomial is\n");
        for(i=n;i>=1;i--)
        {
            if(power<0)
            {
                break;
            }

            if(d[i]>0)
            printf(" + ");
            else if(d[i]<0)
                printf(" - ");
                else
                printf(" ");
            printf("%dx^%d",d[i],i-1);
        }
    getch();
    }
