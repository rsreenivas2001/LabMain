#include<stdio.h>
void main()
{
    char a[50],b[50],c[100];
    int i,f=0,n;
    printf("Enter first string ");
    scanf("%s",a);
    printf("Enter second string ");
    scanf("%s",b);
    printf("Enter third string ");
    scanf("%s",c);
    for(i=0;a[i]!='\0';i++)
    {
        if(c[i]==a[i])
            f=0;
        else
            f=1;
    }
    if(f==1)
    {
        printf("\nThird string is not a valid shuffle of two strings");
        exit(0);
    }
    n=i;
    for(i=0;b[i]!='\0';i++)
    {
        if(c[i+n]==b[i])
            f=0;
        else
            f=1;
    }
    if(f==0)
        printf("\nThird string is valid shuffle of two strings");
    else
        printf("\nThird string is not a valid shuffle of two strings");
}
