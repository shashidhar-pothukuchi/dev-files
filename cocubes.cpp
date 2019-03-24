#include<stdio.h>


char ClassifyGivenSteel(int h,float c,int ts){
	
	int i,steelc[3] = {0,0,0};
	
	steelc[0] =(h>60?1:0);
	steelc[1]=(c>0.8?1:0);
	steelc[2]=(ts>5700?1:0);
switch(steelc[0]){
	
	case 0 : if(steelc[1]==1){
				if(steelc[2]==1)
					return('D');
				else
					return('E');
				}
			else if(steelc[1]==0){
				if(steelc[2]==1)
					return('E');
				else
					return('F');
			}break;
			
	case 1 :  if(steelc[1]==1){
				if(steelc[2]==1)
					return('A');
				else
					return('B');
				}
			else if(steelc[1]==0){
				if(steelc[2]==1)
					return('C');
				else
					return('E');
			}break;	
			
	}
}



int main(){
	
	printf("%c",ClassifyGivenSteel(60,0.4,5100));
}
