#include<stdio.h>
#include<string.h>
void main()
{
    char s[100],a[100];
    int i,j,k;
    printf("Enter first string ");
    scanf("%s",a);
    printf("Enter second string ");
    scanf("%s",s);
    for(i=0;a[i]!='\0';i++)
        for(j=0;s[j]!='\0';j++)
        {
            if(a[i]==s[j])
                for(k=j;s[k]!='\0';k++)
                    s[k]=s[k+1];
        }
    printf("%s",s);
}
