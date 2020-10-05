#include<stdio.h>
#include<stdlib.h>
typedef struct
        {
                int sid;
                char name[100];
                int sq,sl,se,ts;
        }stud;
stud m;
int i;
void display(stud x)
        {
                printf("\nstudent no: %d",x.sid);
                printf("\nstudent name: %s",x.name);
                printf("\nlab score:%d\nquiz score:%d\nexam score%d\n",x.sq,x.sl,x.se);
        }
void main(int argc,char*argv[])
{
        stud s[100];
        if(argc!=3)
        {
                printf("\n file error\n");
                exit(0);
        }
        FILE *fp,*p;
        int n;
        fp=fopen(argv[1],"w");
        {
                printf("\n enter no of students\n");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                        printf("\n enter the student id\n");
                        scanf("%d",&s[i].sid);
                        printf("\n enter the name\n");
                        scanf("%s",s[i].name);
                        printf("\n enter the quiz score\n");
                        scanf("%d",&s[i].sq);
                        printf("\n enter the lab score\n");
                        scanf("%d",&s[i].sl);
                        printf("\n enter the exam score\n");
                        scanf("%d",&s[i].se);
                        fwrite(&s[i],sizeof(m),1,fp);
                }
        }
                fclose(fp);
                fp=fopen(argv[1],"r");
                while(fread(&m,sizeof(m),1,fp))
                {
                         p=fopen(argv[2],"w");
                        display(m);
                        int ts;
                        ts=m.sq+m.sl+m.se;
                        fwrite(&ts,sizeof(ts),1,p);
                        fclose(p);
                        p=fopen(argv[2],"r");
                        printf("total score:");
                        while(fread(&ts,sizeof(ts),1,p))
                        printf("%d\n",ts);

                }
        fclose(fp);
                fclose(p);
}




