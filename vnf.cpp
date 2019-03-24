#include<stdio.h>
#include<stdlib.h>

typedef struct _SYSTEMTIME {
	WORD wYear;
	WORD wMonth;
	WORD wDay;
	WORD wHour;
	WORD wMinute;
	WORD wSecond;
	
};
main()
{
	int price,c;
	float n;
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	printf("1:Rice(kg) 2:salt(500g) 3:sugar(pkt) 4:tomatoes(kg) 5:potatoes(kg) ");
	printf("6:Ladies fingers(kg) 7:cucumber(kg) 8:brinjal(kg) 9:onions(kg) 10:raddish(kg)\n");
	printf("%d/%d/%d %d:%d:%d \n",str_t.wDay,str_t.wMonth,str_t.wYear,str_r.wHour,str_t.wMinute,str_t.wSecond);
	}
