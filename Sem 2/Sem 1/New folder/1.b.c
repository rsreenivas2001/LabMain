#include<stdio.h>
int isvowel(char *p)
{
    int c=0,i;
    for(i=0;p[i]!='\0';i++)
        if((p[i]=='a')||(p[i]=='e')||(p[i]=='i')||(p[i]=='o')||(p[i]=='u'))
            c++;
    return c;
}
void main()
{
    char str[50];
    int count;
    printf("Enter a string ");
    scanf("%s",str);
    count=isvowel(str);
    printf("Given string contains %d vowels",count);
}



