#include<stdio.h>
#include<string.h>
void main()
{
    char s[100],a[100];
    int i,j,n,c=0;
    printf("Enter a string ");
    scanf("%s",s);
    printf("Enter a smaller string ");
    scanf("%s",a);
    n=strlen(a);
    for(i=0;s[i]!='\0';i++)
    {
        if(a[0]==s[i])
        {
            for(j=0;j<n;j++)
            {
                if(a[j]==s[i+j])
                {
                    c++;
                    if(c==n)
                        break;
                }
            }
        }
        if(c==n)
            break;
    }
    if(c==n)
        printf("\nSmaller string is a subset of bigger string");
    else
        printf("\nSmaller string is not a subset of bigger string");
}
