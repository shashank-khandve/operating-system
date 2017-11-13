#include<stdio.h>
#include"arith.h"
int main()
{
	int i,j;
	printf("enter the values for div and mul\n");
	scanf("%d%d", &i,&j);
	printf("div: %d mul: %d\n",div(i,j),mul(i,j));
}
