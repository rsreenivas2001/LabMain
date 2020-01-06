#include<stdio.h>
void main()
{
    char s[100],a[100],b[100];
    int i,z=0,k=0;
    printf("Enter the string\n");
    scanf("%[^\n]s",s);

    for(i=0;s[i]!='\0';i++)
    {
    if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'||s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U')
    {
    b[k]=s[i];
    k++;
    }
    else
    {
    a[z]=s[i];
    z++;
    }
    }
    b[k]='\0';
    a[z]='\0';
    printf("The vowels are %s",b);
    printf("\nThe consonants are %s",a);

}
