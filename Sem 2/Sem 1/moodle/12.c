#include<stdio.h>
#include<string.h>


void main()
{
    int i,l=0,j,max=0;
    char s[100],a[100],ch;
    printf("Enter the first string\n");
    scanf("%[^\n]s",s);
    printf("\nEnter the second string\n");
    scanf("%*c%[^\n]s",a);
    for(i=0;s[i]!='\0';i++)
    {
        for(j=0;s[j]!='\0';j++)
         {
            if(s[i]==a[j])
                {
                    l++;
                    break;
                }
         }
    }
        if(strlen(s)==l)
           {
            printf("\nThe entered words are valid shuffle\n");
           }
        else
            printf("\nThe entered words are not a valid shuffle\n");


}
