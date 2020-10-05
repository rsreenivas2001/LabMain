#include<stdio.h>
#include<ctype.h>
void main()
{
    char s[100],a[100],b[100];
    int i,j,n=1;
    strcpy(a,"Hello");
    for(i=0;i<5;i++)
    {
        for(j=0;j<n;j++)
        printf("%c",a[j]);
        if(n<=5)
        {
            n++;
            printf("\n");
        }
    }
}
