#include<stdio.h>
#include<pthread.h>

void *printthread(void *data)
{
	printf("i am in thread\n");
}

int main()
{
	pthread_t tid;
	int a;
	printf("before\n");
	a=pthread_create(&tid,NULL,printthread,NULL);
	printf("after%d\n",a);
	pthread_join(tid,NULL );

	return 0;
}	
