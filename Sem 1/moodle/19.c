#include<stdio.h>
#include<string.h>
#include <ctype.h>
void main()
{
    char s[100],a[100][100];
    int i=0,j=0,n=0,p=0,k;
    printf("Enter a line ");
    scanf("%[^\n]s",s);
    for(i=0;s[i]!='\0';i++)
    {
            if(isdigit(s[i]) || (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
                    a[p][j]=s[i];
                    j++;
            }
        else{
                p++;
                j=0;
        }
    }
    char temp;
     for(i=0;i<=p;i++){
        for(j=0,k=strlen(a[i])-1;j<strlen(a[i])/2;j++,k--){
            temp=a[i][j];
            a[i][j]=a[i][k];
            a[i][k]=temp;
        }
     }
     char res[100];
     for(i=0;i<=p;i++){
        strcat(res,a[i]);
        strcat(res," ");
     }
     printf("Result : %s\n",res);
}
