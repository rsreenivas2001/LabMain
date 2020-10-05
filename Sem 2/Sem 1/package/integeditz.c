#include<stdio.h>
    #include<conio.h>
    #include<stdlib.h>
    #include<math.h>
    void main()
    {
        int a[10],b[10],i,n,m,d[10],c[10];
        c[0]=0;
        c[1]=0;
        float in[10],zx;

        printf("Enter the highest degree of the polynomial\n");
        scanf("%d",&n);
        printf("Enter the lowest degree of the polynomial (Enter 0 if no negative powers) \n");
        scanf("%d",&m);
        for(i=n;i>=0;i--)
        {
            printf("Enter the co-efficient of x^%d:",i);
            scanf("%d",&a[i]);

        }
        for(i=2;i<=abs(m);i++)
        {
            printf("Enter the co-efficient of x^%d:",-i);
            scanf("%d",&b[i]);

        }
        printf("Given polynomial is\n");
        for(i=n;i>=0;i--)
        {
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
        for(i=2;i<=abs(m);i++)
        {
            if(b[i]>0)
            {
             printf(" + ");
            }
            else if(b[i]<0)
                printf(" - ");
                else
                printf(" ");
            printf("%dx^%d",abs(b[i]),-i);
        }

        //To find integral
        for(i=n;i>=0;i--)
        d[i]=a[i];
        for(i=2;i<=abs(m);i++)
        c[i]=b[i];
        printf("\n Integral of the given polynomial is\n");
        for(i=n;i>=0;i--)
        {
            if(d[i]>0)
            printf(" + ");
            else if(d[i]<0)
                printf(" - ");
                else
                printf(" ");
            zx=d[i]/(float)(i+1);
            printf("(%.2f)x^%d",zx,i+1);
        }
        for(i=2;i<=abs(m);i++)
        {
            if(c[i]>0)
            printf(" + ");
            else if(c[i]<0)
                printf(" - ");
                else
                printf(" ");
                zx=c[i]/(float)(1-i);
            printf("(%.2f)x^%d",zx,-i+1);
        }
    getch();
    }




