#include<stdio.h>
#include<string.h>
#include<limits.h>
void main()
{
    char s[100],a;
    int i,j,n,c=0,max=INT_MIN;
    printf("Enter a string ");
    scanf("%s",s);
    n=strlen(s);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(s[i]==s[j])
                c++;
        if(c>max)
        {
            max=c;
            a=s[i];
        }
        c=0;
    }
    printf("%c occurs maximum times in the given string",a);
}
