#include<stdio.h>
#include<string.h>
void main()
{
    char s[100],a;
    int i,j,n;
    printf("Enter the character to be removed from the string ");
    scanf("%c",&a);
    printf("Enter a string ");
    scanf("%s",s);
    n=strlen(s);
    for(i=0;i<n;i++)
    {
        if(s[i]==a)
        {
            for(j=i;j<n;j++)
                s[j]=s[j+1];
        }
        n--;
    }
    printf("%s",s);
}
