#include<stdio.h>


int * transpose(int a[10][10], int n)
{
	static int temp[10];
	int i,j,count=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			temp[count++]=a[j][i];
	}
	return temp;
}
int main()
{
	int a[10][10],n,i,j;
	int *p;
	printf("Enter the no. of rows\n");
	scanf("%d",&n);
	printf("Elements\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");	
	}
	p=transpose(a,n);
	for(i=0;i<n;i++)
		a[i][j]=*(p+i);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");	
	}
		
}
