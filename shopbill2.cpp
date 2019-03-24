#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct bill 
{
	char name[30];
	int code;
	int price;
	int quantity;
}b;

typedef struct temp
{
	char name[30];
	int price;
	int tsum;
	int quantity;
}t;

void insertnew()
{
	struct bill b;
	FILE *fp;
	printf("Enter name of item\n");
	scanf("%s",b.name);
	printf("Enter code no. for item \n");
	scanf("%d",&b.code);
	printf("Enter price \n");
	scanf("%d",&b.price);
	
	fp=fopen("data.dat","a");
	if(fp==NULL)
		printf("File not found\n");
	else
	{
		fwrite(&b, sizeof(struct bill), 1, fp);
		rewind(fp);
		printf("Record insertion successful\n");
	}
	fclose(fp);
}


int addvalue()
{
	FILE *fp;
	FILE *fpp;
	int c,s=0,n=0,i,k=0,p;
	struct bill b;
	struct temp t[100];
	while(1)
	{
		printf("1.Add items  2.Bill\n");
		scanf("%d",&c);
		switch(c)
		{
		
		case 1:	fp=fopen("data.dat","r");
				while(fread(&b, sizeof(struct bill), 1, fp))
				{
					p=b.code;
					printf("%s::%d\n",b.name,p);
				}
				rewind(fp);
				printf("Enter code of product \n");
				scanf("%d",&c);
				
				if(fp==NULL)
				{
					printf("File does not exist\n");
					exit(1);
				}
				else
				{
					while(fread(&b, sizeof(struct bill), 1, fp))
					{	
						p=b.code;
						if(c==p)
						{  
							printf("Found\n");
							k++;
							break;
						}
					}
					if(k==0)
					{
						printf("Item not found\n");
						exit(1);
					}
				}
				
				printf("%s\n",b.name);
				printf("Enter quatity\n");
				scanf("%d",&b.quantity);
				strcpy(t[n].name,b.name);
				t[n].quantity=b.quantity;
				t[n].tsum=b.price*b.quantity;
				s=s+t[n].tsum;
				fpp=fopen("records.dat","a");
				if(fpp==NULL)
					printf("File not found\n");
				else
				{
					fwrite(&b, sizeof(struct bill), 1, fpp);
					printf("Done\n");
					n++;
				}	
				fclose(fp);
				fclose(fpp);
				break;
	
		case 2:printf("\t\tABC\n");
				time_t p;
				time(&p);
				printf("\t\t%s \n",ctime(&p));
				for(i=0;i<n;i++)
					printf("%s * %d = %d\n",t[i].name,t[i].quantity,t[i].tsum);
				printf("__________________________________\n");
				printf("Total bill\t=\t %d",s);
				fclose(fpp);
				exit(0);
	
		}
	}
}

int main()
{	
	int a,i;
		printf("Enter choice\n");
		printf("1.Add products  2.Shop  4.exit\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:insertnew();
					break;
					
			case 2:addvalue();
					break;
			default:exit(0);						
		}	
}
