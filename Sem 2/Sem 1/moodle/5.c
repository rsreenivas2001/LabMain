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
    for(i=0;s[i]!='\0';i++)
    {
        if(islower(s[i]))
           s[i]=toupper(s[i]);
        else
           s[i]=tolower(s[i]);
    }
    printf("\nThe toggled string is\n");
    printf("%s",s);
}
