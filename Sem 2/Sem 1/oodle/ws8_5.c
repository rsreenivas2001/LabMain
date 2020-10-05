#include<stdio.h>
#include<string.h>
void main()
{
    char s[100];
    int i;
    printf("Enter a string ");
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++)
    {
        if(isupper(s[i]))
            s[i]+=32;
        else
            s[i]-=32;
    }
    printf("%s",s);
}
