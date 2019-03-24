#include<stdio.h>

 struct Ratio
{
	int x,y;
	float z;
};

int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b ,a % b);
 
}


int main()
{
	struct Ratio p,q;
	int n,k1,k2,m;
	printf("1.Print a/b form \n 2.Sum of Ratioal numbers \n 3.Product of Rational numbers \n 4.Sort in asending order \n 5.Print in simplest order \n");
	scanf("%d",&n);
	switch(n)
	{
		case 1 : printf("Enter a and b\n");
				 scanf("%d %d",&p.x,&p.y);
				 printf("%d/%d",p.x,p.y);
				 break;
				 
		case 2 : 
				 printf("Enter a and b of first number\n");
	 			 scanf("%d %d",&p.x,&p.y);
				 printf("Enter a and b of second number\n");
				 scanf("%d %d",&q.x,&q.y);
				 k1=(p.x*q.y)+(p.y*q.x);
				 k2=p.y*q.y;
				 m=gcd(k1,k2);
				 k1=k1/m;k2=k2/m;
				 printf("%d/%d",k1,k2);
				 break;
				 
		case 3 : 
				 printf("Enter a and b of first number\n");
				 scanf("%d %d",&p.x,&p.y);
				 printf("Enter a and b of second number\n");
				 scanf("%d %d",&q.x,&q.y);
				 k1=p.x*q.x;
				 k2=p.y*q.y;
				 m=gcd(k1,k2);
				 k1=k1/m;k2=k2/m;
				 printf("%d/%d",k1,k2);
				 break;
				 
		case 4 : struct Ratio k[20];
				 int r[20],i,j,temp;
				 printf("Enter the no. of elements to be sorted\n");
				 scanf("%d",&n);
				 for(i=0;i<n;i++)
				 {
				 	printf("Enter a and b \n");
				 	scanf("%d %d",&k[i].x,&k[i].y);
				 	k[i].z=(float)k[i].x/k[i].y;
				 	//printf("%f",k[i].z);
				 }
				 for(i=0;i<n;i++)
				 	r[i]=0;
				 for(i=0;i<n;i++)
				 {		
					for(j=0;j<i;j++)
		  			{
						if(k[j].z<=k[i].z)
							r[i]++;
						else
							r[j]++;	
				 	}
				 }
				 /*for(i=0;i<n;i++)
				 	printf("%d ",r[i]);*/
				 for(i=0;i<n;i++)
				 {
				 	for(j=0;i<n;j++)
				 	{
				 		if(r[j]==i)
				 		{
				 			printf("%d/%d ",k[j].x,k[j].y);
				 			break;
				 		}
					}
				 }
				break;
		
		case 5 : printf("Enter a and b\n");
				 scanf("%d %d",&p.x,&p.y);
				 m=gcd(p.x,p.y);
				 p.x=p.x/m;p.y=p.y/m;
				 printf("%d/%d",p.x,p.y);
				 break; 		
				
	}
				 	
}








