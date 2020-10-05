#include<stdio.h>
#include<string.h>

void main()
{
    int i;
  struct menu
  {
      char name[100];
      float price;
  };
  FILE *ptr=fopen("Menu.txt","w");
  struct menu items[8];
  strcpy(items[0].name,"Apple");
  items[0].price=55;
  strcpy(items[1].name,"Carrot");
  items[1].price=30;
  strcpy(items[2].name,"Mango");
  items[2].price=60;
  strcpy(items[3].name,"Banana");
  items[3].price=10;
  strcpy(items[4].name,"Potato");
  items[4].price=25;
  strcpy(items[5].name,"Cauliflower");
  items[5].price=40;
  strcpy(items[6].name,"Orange");
  items[6].price=75;
  strcpy(items[7].name,"Onion");
  items[7].price=100;
  for(i=0;i<8;i++)
    fwrite(items[i],sizeof(struct menu),1,ptr);
  fclose(ptr);
}



