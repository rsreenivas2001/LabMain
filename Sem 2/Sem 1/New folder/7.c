#include<stdio.h>
	#include<limits.h>
	void main()
	{
	    int i;
	    char products[][100]={"MP3 Player","WII       ","DVD Player","Digital Camera"};
	    double price[4]={5000,10000,2000,8000},psum=0;
	    int qty[4],qsum=0;
	    for(i=0;i<4;i++)
	    {
	        printf("Eneter the qty quantity of %s sold: ",products[i]);
	        scanf("%d",&qty[i]);
	    }
	    printf("\n\n-----------\n");
	    printf("Sale Table");
	    printf("\n-----------\n\n");
	    printf("\n------------\t------\t\t---\t------\n");
	    printf("Product Unit\tPrice\t\tQTY\tTotal");
	    printf("\n------------\t------\t\t---\t------\n\n");
	    for(i=0;i<4;i++)
	    {
	        printf("%s\t%.1f\t\t%d\t%.1f\n",products[i],price[i],qty[i],price[i]*qty[i]);
	        psum+=price[i]*qty[i];
	        qsum+=qty[i];
	    }
	    printf("\nTotal\t\t\t\t%d\t%.1f\n",qsum,psum);
	    printf("\n------------------------------------------------\n\n");
	    int k,l,max=0,min=INT_MAX;
	    for(i=0;i<4;i++)
	    {
	        if(qty[i]>max)
	        {
	            max=qty[i];
	            k=i;
	        }
	        if(qty[i]<min)
	        {
	            min=qty[i];
	            l=i;
	        }
	    }
	    printf("Product sold most: %s %d\n",products[k],max);
	    printf("Product sold least: %s %d\n",products[l],min);
	}

