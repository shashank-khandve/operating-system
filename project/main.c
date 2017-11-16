#include<stdio.h>
#include <stdlib.h>
int main()
{
	int a;
	while(1)
	{
		printf("enter your choice\n1.SCAN\n2.DUPLICATE\n3.SEARCH WORD\n4.LOG\n5.EXIT\n");
		scanf("%d",&a);
		printf("\n");
		switch (a)
		{
			case 1:
				scan_s();
				break;
			case 2:
				fdupes_s();
				break;
			case 3:
				grep_s();
				break;
			case 4:
				system("cat log.txt");
				break;
			case 5:
				exit(0);
				break;
			
			default:
				printf("invalid entry\n");
		}
	}
	return 0;
}
