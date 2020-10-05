#include<stdio.h>
void main()
{
    char s[100];
    int i,j;
    printf("Enter a string ");
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++)
    {
        for(j=0;j<=i;j++)
            printf("%c",s[j]);
        printf("\n");
    }
}
