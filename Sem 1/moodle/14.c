#include<stdio.h>
#include<string.h>


void main()
{
    int i,l=0,j,max;
    char s[100],a[100],ch;
    printf("Enter the string\n");
    scanf("%s",s);
    printf("\nEnter the character to be removed\n");
    scanf("%*c%c",&ch);
    max=strlen(s);
    for(i=0;i<max;i++)
    {
            if(s[i]==ch)
                {
                    for(j=i;j<max;j++)
                    {
                        s[j]=s[j+1];

                    }
                    max--;
                    i--;
                }


    }
    printf("The edited string is %s\n",s);



}
