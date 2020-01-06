#include<stdio.h>
void main()
{
    int i;
    char s[100];
    printf("Enter the string\n");
    scanf("%[^\n]s",s);
    printf("\nThe enetered string is\n");
    for(i=0;s[i]!='\0';i++)
    printf("%c",s[i]);
}
