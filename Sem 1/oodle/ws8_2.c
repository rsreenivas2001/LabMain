#include<stdio.h>
void main()
{
    char s[100];
    int i;
    printf("Enter a string ");
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++)
        if((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u'))
            printf("%c",s[i]);
    printf("\n");
    for(i=0;s[i]!='\0';i++)
        if((s[i]!='a')&&(s[i]!='e')&&(s[i]!='i')&&(s[i]!='o')&&(s[i]!='u'))
            printf("%c",s[i]);
}
