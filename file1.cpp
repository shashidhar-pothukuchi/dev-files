#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	
	fp=fopen("Sample.txt","r");
	
	if(fp==NULL)
		printf("File not found\n");
	else
	{
			
	while(!feof(fp))
	{
		ch=fgetc(fp);
		
	printf("%c",ch);		
	}
	
	fclose(fp);
}
}
