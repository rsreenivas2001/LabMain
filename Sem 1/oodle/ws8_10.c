#include<stdio.h>
#include<string.h>
void main()
{
    char s[100];
    int i,j,n;
    printf("Enter a string ");
    scanf("%s",s);
    n=strlen(s);
    for(i=n;i>=0;i--)
    {
        for(j=0;j<i;j++)
            printf("%c",s[j]);
        printf("\n");
    }
}
