#include<stdio.h>
#include<string.h>
void main()
{
    char s[100],t;
    int i,n;
    printf("Enter a string ");
    scanf("%s",s);
    n=strlen(s);
    for(i=0;i<n/2;i++)
    {
        t=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=t;
    }
    printf("%s\n",s);
}
