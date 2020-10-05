#include <stdio.h>
#include <math.h>
typedef struct{
    int h,m,s;
    double ms;
}TIME_info;
TIME_info t;
void read(){
    printf("Enter the time in the format hh:mm:ss:ssss\n");
    scanf("%d%d%d%lf",&t.h,&t.m,t.s,&t.ms);
}
void display(TIME_info t){
    //t=conver
    printf("\nThe time is : %d:%d:%d.%0.2lf",t.h,t.m,t.s,t.ms*100);
}
TIME_info convertTime(double realTime){
    TIME_info temp;
    double tmp;
    temp.h=(int)(floor(realTime))/3600;
    temp.m=((int)(floor(realTime))-temp.h*3600)/60;
    temp.s=floor(realTime)-temp.h*3600-temp.m*60;
    temp.ms=modf(realTime,&tmp);
    return temp;
}
TIME_info addTimes(TIME_info one,TIME_info two){
    TIME_info temp;
    temp.h=0;temp.m=0;temp.s=0;temp.ms=0;
    temp.ms+=one.ms+two.ms;
    if(temp.ms>=100){
        temp.ms-=100;
        temp.s+=1;
    }
    temp.s+=one.s+two.s;
    if(temp.s>=60){
        temp.s-=60;
        temp.m++;
    }
    temp.m+=one.m+two.m;
    if(temp.m>=60){
        temp.m-=60;
        temp.h++;
    }
    temp.h+=one.h+two.h;
    return temp;
}
TIME_info subTimes(TIME_info one,TIME_info two){
    TIME_info temp;
    temp.h=0;temp.m=0;temp.s=0;temp.ms=0;
    int flag=0;
    if(one.h>two.h){
        flag=1;
    }
    else if(one.h==two.h){
        if(one.m>two.m){
            flag=1;
        }
        else if(one.m==two.m){
            if(one.s>two.s){
                flag=1;
            }
            else if(one.s==two.s){
                if(one.ms>two.ms || one.ms==two.ms){
                    flag=1;
                }
            }
        }
    }
    if(flag){
        if(one.ms<two.ms){
            temp.s--;
            one.ms+=60;
        }
        temp.ms+=one.ms-two.ms;
        if(one.s<two.s){
            temp.m--;
            one.s+=60;
        }
        temp.s+=one.s-two.s;
        if(one.m<two.m){
            temp.h--;
            one.m+=60;
        }
        temp.m+=one.m-two.m;
        temp.h+=one.h-two.h;
    }
    else{
            if(two.ms<one.ms){
                temp.s--;
                two.ms+=60;
            }
            temp.ms+=two.ms-one.ms;
            if(two.s<one.s){
                temp.m--;
                two.s+=60;
            }
            temp.s+=two.s-one.s;
            if(two.m<one.m){
                temp.h--;
                two.m+=60;
            }
            temp.m+=two.m-one.m;
            temp.h+=two.h-one.h;
        }
        return temp;
}
void main(){
    double sec;
    printf("Enter the time in seconds.\n");
    scanf("%lf",&sec);
    TIME_info newt;
    newt= convertTime(sec);
    //printf("The time in format : %d:%d:%d.%lf",newt.h,newt.m,newt.s,newt.ms);
    display(newt);
    TIME_info t1,t2,add,sub;
    printf("\nEnter the 2 times to perform addition and subtraction.\n");
    printf("Time-1 : \n");
    scanf("%d%d%d%lf",&t1.h,&t1.m,&t1.s,&t1.ms);
    printf("Time-2 : \n");
    scanf("%d%d%d%lf",&t2.h,&t2.m,&t2.s,&t2.ms);
    add=addTimes(t1,t2);
    sub=subTimes(t1,t2);
    printf("Added Time : %d:%d:%d.%0.1lf\n",add.h,add.m,add.s,add.ms);
    printf("Subtracted Time : %d:%d:%d.%0.1lf\n",sub.h,sub.m,sub.s,sub.ms);

}

