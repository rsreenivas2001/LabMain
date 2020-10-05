#include<stdio.h>
#include<math.h>
    void main()
    {
        int a[10],b[10],i,n,m,d[10],c[10],lower_bound,upper_bound;
        c[0]=0;
        c[1]=0;
        float s,s1,s2,power,coeff;

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
            if(a[i]>=0)
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
            if(b[i]>=0)
            {
             printf(" + ");
            }
            else if(b[i]<0)
                printf(" - ");
                else
                printf(" ");
            printf("%dx^%d",abs(b[i]),-i);
        }

        printf("\n\nEnter Lower Boundary Value:\t");
        scanf("%f", &lower_bound);
        printf("Enter Upper Boundary Value:\t");
        scanf("%f", &upper_bound);
        //To find integral
        for(i=n;i>=0;i--)
        d[i]=a[i];
        for(i=2;i<=abs(m);i++)
        c[i]=b[i];
        printf("\n Integral of the given polynomial is\n");
        for(i=n;i>=0;i--)
        {
            power=pow(upper_bound,i+1);
            coeff=d[i]/(i+1);
            s1+=coeff*power;
        }
        for(i=2;i<=abs(m);i++)
        {
            coeff=c[i]/(-i+1);
            power=pow(upper_bound,-i+1);
            s1+=coeff*power;
        }
        for(i=n;i>=0;i--)
        {
            coeff=d[i]/(i+1);
            power=pow(lower_bound,i+1);
            s2+=coeff*power;
        }
        for(i=2;i<=abs(m);i++)
        {
            coeff=c[i]/(-i+1);
            power=pow(lower_bound,-i+1);
            s2+=coeff*power;
        }
        s=(s1-s2);
        printf("%f\n",s1);
        printf("%f\n",s2);
        printf("%f\n",s);
    getch();
    }

