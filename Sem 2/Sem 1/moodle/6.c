#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main()
{
    int i;
    char s[100];
    printf("Enter the string\n");
    scanf("%[^\n]s",s);
    printf("\nThe enetered string is\n");
    printf("%s",s);
    printf("\nThe reversed string is\n");
    printf("%s",strrev(s));
}
