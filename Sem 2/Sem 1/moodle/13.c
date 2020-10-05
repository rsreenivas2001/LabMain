#include<stdio.h>
#include<string.h>


void main()
{
    int i,l=0,j,max=0;
    char s[100],ch;
    printf("Enter the string\n");
    scanf("%[^\n]s",s);
    printf("\nThe enetered string is");
    printf("%s\n",s);
    for(i=0;s[i]!='\0';i++)
    {
        l=0;
        for(j=0;s[j]!='\0';j++)
         {
            if(s[i]==s[j])
                l++;
         }
        if(l>max)
           {
            max=l;
            ch=s[i];
           }
    }
    printf("\nThe character %c occurs %d times \n\n",ch,max);
}
