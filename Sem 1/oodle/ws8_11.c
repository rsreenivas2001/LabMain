#include<stdio.h>
#include<string.h>
#include<math.h>
void main()
{
    char s[100];
    int n=0,i,l;
    printf("Enter a numerical string ");
    scanf("%s",s);
    l=strlen(s);
    for(i=0;i<l;i++)
        n=(n*10)+(s[i]-48);
    printf("%d",n);
}
