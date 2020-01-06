#include<stdio.h>
#include<time.h>
struct menu
  {
      char name[100];
      float price;
  };
void main()

{
   time_t rawtime;
  struct tm * timeinfo;
  struct menu list[8]
  FILE *ptr=fopen("Menu.txt","r")
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ( "Current local time and date: %s", asctime (timeinfo) );

  printf("MENU : \n");
  for(i=0;i<8;i++)
  {
      fread(list[i],sizeof(struct menu),1,ptr);
      printf("%s---%f",list[i].name,list[i].price)
  }
}
