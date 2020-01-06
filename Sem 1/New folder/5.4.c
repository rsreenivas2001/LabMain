#include<stdio.h>

void reverse(char *s)
{
    if(*s)
    {
        reverse(s+1);
        printf("%c",*s);
    }
}

void main()
{
    char str[100]={0};
    printf("Enter the string:\n");
    scanf("%[^\n]s",str);
    printf("The reversed string is:\n");
    reverse(str);
    printf("\n");
}
