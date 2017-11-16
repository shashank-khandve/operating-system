#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	
	char a[128],b[128];
	printf("enter the file name\n");
	char PATH=
	gets(a);
	fopen("PATH",O_RDONLY);
	printf("enter the word to be searched\n");
	gets(b);
	printf("the total number of word comes in file is=");
	system("grep -c b a ");
	
	system("grep -n b a ");
}
