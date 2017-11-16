#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NORMAL_COLOR  "\x1B[0m"
#define GREEN  "\x1B[32m"
#define BLUE  "\x1B[34m"
void grep_s()
{
	
	char a[1028],b[128],c[1024],d[1024];
	system("date>>log.txt");
	strcpy(c,"grep -c ");
	strcpy(d,"grep -n ");
	printf("enter the word to be searched\n");
	scanf("%s",b);
	fflush(stdin);
	strcat(c,b);
	strcat(d,b);
	printf("enter the file path\n");
	scanf("%s",a);
	fflush(stdin);
	strcat(c," ");
	strcat(d," ");
	strcat(c,a);
	printf("%s\n", BLUE);
	printf("Number of times string occured\n");
	system(c);
	strcat(c,">>log.txt");
	system("(echo Number of times string occured)>>log.txt");
	system(c);
	strcat(d,a);
	printf("%s\n", GREEN);
	printf("Line no. in which string occured\n");
	system(d);
	strcat(d,">>log.txt");
	system("(echo Line no. in which string occured)>>log.txt");
	system(d);
	printf("%s\n", NORMAL_COLOR);
	return;

}
