#include<stdio.h>
#include<string.h>
void main()
{
    char s[100];
    int u=0,l=0,sp=0,i;
    printf("Enter a string ");
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++)
    {
        if(isupper(s[i]))
            u++;
        else if(islower(s[i]))
            l++;
        else if((s[i]>=33)&&(s[i]<=47))
            sp++;
    }
    printf("No.of upper case letters %d\n",u);
    printf("No.of lower case letters %d\n",l);
    printf("No.of special characters %d\n",sp);
}
