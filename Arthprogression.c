#include<stdio.h>
#include<math.h>
int main(){
	int n,i;
	float sum=0;
	scanf("%d",&n);
    if(n>0){
        sum+=1;
        printf("%d",(int)sum);
    }
	for(i=1;i<n;i++){
		sum+=(float)(2*i+1)/pow((double)2,(double)i);
		printf("+%d/%d",(2*i+1),(int)pow((double)2,(double)i));

	}
	printf("=%.2f",sum);
}