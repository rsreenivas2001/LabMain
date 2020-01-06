#include<stdio.h>
#include<string.h>


void main()
{
    int i,l=0;
    char s[100],ch;
    printf("Enter the string\n");
    scanf("%[^\n]s",s);
    printf("\nThe enetered string is\n");
    printf("%s",s);
    printf("\nEnter the character whose occurence is to be counted");
    scanf("%*c%c",&ch);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]==ch)
           l++;
    }
    printf("\nThe character %c occurs %d times \n",ch,l);
}
