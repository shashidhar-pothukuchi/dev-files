#include<stdio.h>
#include<stdlib.h>
#include<time.h>
	struct bill
	{
		char name[25];
		int code;
		int price;
		int quantity;
	};

int value(int x)
{
	switch(x)
	{
		case 1:return(20);
				break;
		case 2:return(35);
				break;
		case 3:return(65);
				break;
		case 4:return(30);
				break;
		case 5:return(20);
				break;
		default:printf("Product not found\n");
				return(0);						
	}
}
void name(int x)
{
	switch(x)
	{
		case 1:printf("Salt ");
				break;
		case 2:printf("Rice ");
				break;
		case 3:printf("Diary Milk silk ");	
				break;
		case 4:printf("coke ");
				return;
		case 5:printf("Lays ");
				break;
		default:printf("NULL");
												
	}
}	
int main()
{

	struct bill b[100];
	int a,cod,i=0,n=0,k,s=0;
	time_t t;
	time(&t);
	printf("1:salt 2:Rice 3:Diary milk silk 4:coke 5:Lays \n");
	while(1)
	{
		printf("1.Add value 2.Bill\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:printf("Enter product code\n");
					scanf("%d",&cod);
					b[i].code=cod;
					k=value(cod);
					printf("Enter quantity\n");
					scanf("%d",&b[i].quantity);
					b[i].price=k*b[i].quantity;
					s=s+b[i].price;
					i++;n++;
					break;
			case 2:printf("\t\t\tabc stores\n");
					printf("\t\t%s \n",ctime(&t));
					for(i=0;i<n;i++)
					{
						name(b[i].code);
						printf("  *  %d  -  %d\n",b[i].quantity,b[i].price);
					}
					printf("______________________\n");
					printf("Total bill = %d",s);
					exit(0);
		}
	}
	
	
}
