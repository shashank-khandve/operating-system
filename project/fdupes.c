#include<stdio.h>
#include<string.h>
void fdupes_s()
{
	system("date>>log.txt");
	char a[1024]={0},b[1024]={0};
	strcpy(b,"fdupes -rd ");
	printf("enter the path\n");
	scanf("%s",a);
	fflush(stdin);
	strcat(b,a);
	printf("Duplicate files are\n");
	system(b);
	strcat(b,">>log.txt");
	system("(echo Duplicate files are)>>log.txt");
	system(b);
	return;
}
