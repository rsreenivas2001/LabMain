    #include<stdio.h>
    #include<conio.h>
    #include<stdlib.h>
    #include<math.h>
void main()
    {
        int qwe,op;
        char qw;
        ls:
        system("cls");
        system("COLOR 0A");
        printf("\t\t\t\t\tHELLO\n\n");


        for(qwe=0;qwe<80;qwe++)
        printf("-");
        printf("\nChoose an option below to perform on a polynomial :\n\n");
        printf(" 1. Differentiation \n");
        printf(" 2. Indefinite Integration \n");
        printf(" 3. Definite Integration \n");
        printf(" 4. Exit \n");
         for(qwe=0;qwe<80;qwe++)
        printf("-");
        printf("\n\n Enter your choice : ");
        scanf("%d",&op);
        switch(op)
        {
        case 3:
        {
        system("cls");
        system("COLOR 0B");

        int a[10],b[10],i,n,m,d[10],c[10];
        c[0]=0;
        c[1]=0;
        double sum=0,sum1=0,sum2=0,zx,xy,lower_bound,upper_bound;

        printf("\n\nEnter the highest degree of the polynomial : ");
        scanf("%d",&n);
        printf("Enter the lowest negative degree of the polynomial (Enter 0 if no negative powers) : ");
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

        printf("\nEnter Lower Boundary Value:\t");
        scanf("%lf", &lower_bound);
        printf("Enter Upper Boundary Value:\t");
        scanf("%lf", &upper_bound);
        //To find integral
        for(i=n;i>=0;i--)
        d[i]=a[i];
        for(i=2;i<=abs(m);i++)
        c[i]=b[i];
        printf("\n Integral of the given polynomial is\n");

        for(i=n;i>=0;i--)
        {
            xy=(d[i]/(double)(i+1));
            zx=pow(upper_bound,(double)i+1);
            sum1+=(xy*zx);
        }
        for(i=2;i<=abs(m);i++)
        {
            xy=(c[i]/(double)(1-i));
            zx=pow(upper_bound,(double)1-i);
            sum1+=(xy*zx);
        }
        for(i=n;i>=0;i--)
        {
            xy=(d[i]/(double)(i+1));
            zx=pow(lower_bound,(double)i+1);
            sum2+=(xy*zx);
        }
        for(i=2;i<=abs(m);i++)
        {
            xy=(c[i]/(double)(1-i));
            zx=pow(lower_bound,(double)1-i);
            sum2+=(xy*zx);
        }
        sum=sum1-sum2;
        //printf("%lf\n",sum1);

        //printf("%lf\n",sum2);

        printf("%.3lf\n",sum);
    getch();
    printf("\n\nTo Continue press Y and To Exit press N : ");
    scanf("%*c%c",&qw);
    if(qw=='y'||qw=='Y')
    goto ls;
    else if(qw=='n'||qw=='N')
    exit(1);
    break;
        }

    case 1:
   {
       system("cls");
         system("COLOR 0B");
        int a[10],i,n,d[10],power;
        float in[10];

        printf("Enter the order of the polynomial : ");
        scanf("%d",&n);
        for(i=n;i>=0;i--)
        {
            printf("Enter the co-efficient of x^%d :",i);
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

            if(d[i]>=0)
            printf(" + ");
            else if(d[i]<0)
                printf(" - ");
                else
                printf(" ");
            printf("%dx^%d",d[i],i-1);
        }
    getch();
      printf("\n\nTo Continue press Y and To Exit press N : ");
    scanf("%*c%c",&qw);
    if(qw=='y'||qw=='Y')
    goto ls;
    else if(qw=='n'||qw=='N')
    exit(1);
    break;
    }

    case 2:
    {
        system("cls");
         system("COLOR 0B");
        int a[10],b[10],i,n,m,d[10],c[10];
        c[0]=0;
        c[1]=0;
        float in[10],zx;

        printf("Enter the highest degree of the polynomial : ");
        scanf("%d",&n);
        printf("Enter the lowest negative degree of the polynomial (Enter 0 if no negative powers) : ");
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
    printf("\n\nTo Continue press Y and To Exit press N : ");
    scanf("%*c%c",&qw);
    if(qw=='y'||qw=='Y')
    goto ls;
    else if(qw=='n'||qw=='N')
    exit(1);
    break;
    }
    case 4:
       {
           exit(1);
       }
    default:
    {
        printf("\n\n Wrong choice Entered...!!..TRY AGAIN..!!");
        goto ls;
    }
        }
    }





