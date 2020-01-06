
#include<stdio.h>
#include<string.h>
void main()
{
    char s[100],a[100];
    int i,j,k,l,n,c=0;
    printf("Enter a string ");
    scanf("%s",s);
    printf("Enter a word to be removed ");
    scanf("%s",a);
    n=strlen(a);
    for(i=0;s[i]!='\0';i++)
    {
        if(a[0]==s[i])
        {
            for(j=0;j<n;j++)
            {
                if(a[i]==s[i+j])
                    c++;
                if(c==n)
                    break;
            }
            for(k=i;s[k]!='\0';k++)
                for(l=i;s[l]!='\0';l++)
                    s[l]=s[l+1];
        }
    }
    printf("%s",s);
}
