#include<stdio.h>
#include<string.h>
void main()
{
    char s[100],a;
    int i,c=0;
    printf("Enter the character to be searched ");
    scanf("%c",&a);
    printf("Enter a string ");
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++)
        if(s[i]==a)
            c++;
    printf("%c occurs %d times",a,c);
}
