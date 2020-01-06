#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void main(){
    FILE *fp1=fopen("file1.txt","w");
    FILE *fp2=fopen("file2.txt","w");
    FILE *fp3=fopen("file3.txt","w");
    int val,c1=0,c2=0,c3=0;
    printf("\nEnter the voter ID's given by first official.\nNote : To end the list press 0.\n");
    scanf("%d",&val);
    while(val!=0){
        c1++;
        fprintf(fp1,"%d ",val);
        scanf("%d",&val);
    }
    fclose(fp1);
    fp1=fopen("file1.txt","r");
    printf("\nNo. of values : %d\n",c1);
    int vals1[10],i=0,j=0;
    while(!feof(fp1)){
        fscanf(fp1,"%d",&vals1[i]);
        i++;
    }
    fclose(fp1);
     printf("\nEnter the voter ID's given by second official.\nNote : To end the list press 0.\n");
    scanf("%d",&val);
    while(val!=0){
        c2++;
        fprintf(fp2,"%d ",val);
        scanf("%d",&val);
    }
    fclose(fp2);
    fp2=fopen("file2.txt","r");
    printf("\nNo. of values : %d\n",c2);
    int vals2[10];
    i=0;
    while(!feof(fp2)){
        fscanf(fp2,"%d",&vals2[i]);
        i++;
    }
    fclose(fp2);
     printf("\nEnter the voter ID's given by third official.\nNote : To end the list press 0.\n");
    scanf("%d",&val);
    while(val!=0){
        c3++;
        fprintf(fp3,"%d ",val);
        scanf("%d",&val);
    }
    fclose(fp3);
    fp3=fopen("file3.txt","r");
    printf("\nNo. of values : %d\n",c3);
    int vals3[10];
    i=0;
    while(!feof(fp3)){
        fscanf(fp3,"%d",&vals3[i]);
        i++;
    }
    fclose(fp3);
    int a1[10]={0},a2[10]={0},a3[10]={0},a[30],q,w,k,x=0;



    for(q=0;q<10;q++)
    {
        for(w=0;w<10;w++)
        {
            if(vals1[q]==vals2[w])
            a1[q]++;
            if(vals1[q]==vals3[w])
            a1[q]++;
        }
    }
    for(q=0;q<10;q++)
    {
        for(w=0;w<10;w++)
        {
            if(vals2[q]==vals1[w])
            a2[q]++;
            if(vals2[q]==vals3[w])
            a2[q]++;
        }
    }


        for(q=0;q<10;q++)
        {
            if(a1[q]>=1)
            {
                a[k]=vals1[q];
                k++;
            }
        }




        for(q=0;q<10;q++)
        {
            if(a2[q]>=1)
            {
                for(w=0;w<k;w++)
                {
                    if(vals2[w]==a[k])
                    x=1;
                }
                if(x!=1)
                {
                a[k]=vals2[q];
                k++;
                }
            }
        }
        for(i=0;i<k;i++)
        printf("%d",a[i]);
    }


