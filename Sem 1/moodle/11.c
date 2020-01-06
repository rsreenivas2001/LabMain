#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
void main()
{
    char s[100];
    int i,z=0,k,ans=0,j;
    printf("Enter the numeric string\n");
    scanf("%s",s);
    z=strlen(s);
    k=pow(10,z-1);
    for(j=0;s[j]!='\0';j++)
    {
      ans+=(s[j]-48)*k;
      k=k/10;
    }
    printf("the numeric string in int is %d \n",ans);
}
