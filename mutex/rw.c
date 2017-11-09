


#include<stdio.h>
#include<pthread.h>
int a=50;
pthread_rwlock_t rwlock;
pthread_t tidread1,tidread2,tidwrite1,tidwrite2;
void *read1Thread(void *data)			
{
	pthread_rwlock_rdlock(&rwlock)
	{
	printf("read1:%d\n"a);
	}
}
void *read1Thread(void *data)
{
	pthread_rwlock_rdlock(&rwlock)
	{
	printf("read2:%d\n"a);
	}
}
void *write1Thread(void *data)
{
	pthread_rwlock_wrlock(rwlock)
	{
	a=a+10;
	}
}
void *write2Thread(void *data)
{
	pthread_rwlock_wrlock(rwlock)
	{
	a=a+20;
	}
}
	
	
	
	
	
int main()
{
	pthread_rwlock_init(&rwloclk,NULL);
	pthread_create(&tidread1,NULL,read1Thread,NULL);
	pthread_create(&tidread2,NULL,read2Thread,NULL);
	pthread_create(&tidwrite1,NULL,write1Thread,NULL);
	pthread_create(&tidwrite2,NULL,write2Thread,NULL);
	
	pthread_join(write1thread,NULL);
	pthread_join(write2thread,NULL);
	pthread_join(read1thread,NULL);
	pthread_join(read2thread,NULL);
	pthread_rwlock_destroy(&rwloclk);
