#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>
int a,b,sum;
sem_t init,add;
void *Initthread(void *data)
{
	while(1)
	{
		sem_wait(&init);
		scanf("%d",&a);
		scanf("%d",&b);
		sem_post(&add);
	}
}
void *Addthread(void *data)
{
	while(1)
	{
		sem_wait(&add);
		sum=a+b;
		printf("sum:%d\n",sum);
		sem_post(&init);
	}
}

int main()
{
	int a=5;
	sem_init(&init,0,1);
	sem_init(&add,0,0);
	pthread_t tidInit,tidAdd;
	pthread_create(&tidInit,NULL,Initthread,NULL);
	pthread_create(&tidAdd,NULL,Addthread,NULL);
	//pthread_join(tidInit,NULL );
	pthread_join(tidAdd,NULL );
	return 0;
}	


