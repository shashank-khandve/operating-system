#include<stdio.h>
#include<pthread.h>
void *incthread(void *data)
{
	while(1)
	printf("inc:%d\n",++data);
}
void *decthread(void *data)
{
	while(1)
	printf("dec:%d\n",--data);
}

int main()
{
	int a=5;
	pthread_t tidinc,tiddec;
	pthread_create(&tidinc,NULL,incthread,a);
	pthread_create(&tiddec,NULL,decthread,a);
	
	pthread_join(tidinc,NULL );
	pthread_join(tiddec,NULL );
	return 0;
}	
