#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
int a=50;
pthread_rwlock_t rwlock;
pthread_t tidread1,tidread2,tidwrite1,tidwrite2;
void *read1Thread(void *data)			
{
	sleep(2);
	printf("i am in read1\n");
	pthread_rwlock_rdlock(&rwlock);
	printf("read1:%d\n",a);
	sleep(2);
	printf("i am in read1 rwlock\n");
	pthread_rwlock_unlock(&rwlock);
}
void *read2Thread(void *data)
{ 
	sleep(2);
	printf("i am in read2\n");
	pthread_rwlock_rdlock(&rwlock);
	printf("read2:%d\n",a);
	sleep(2);
	printf("i am in read2 rwlock\n");
	pthread_rwlock_unlock(&rwlock);
}
void *write1Thread(void *data)
{
	sleep(6);
	printf("i am in write1\n");
	pthread_rwlock_wrlock(&rwlock);
	a=a+10;
	printf("i am in write1 rwlock\n");
	pthread_rwlock_unlock(&rwlock);
}
void *write2Thread(void *data)
{
	printf("i am in write2\n");
	pthread_rwlock_wrlock(&rwlock);
	printf("i am in write2 rwlock\n");
	a=a+20;
	sleep(4);
	pthread_rwlock_unlock(&rwlock);
}
int main()
{
	pthread_rwlock_init(&rwlock,NULL);
	pthread_create(&tidread1,NULL,read1Thread,NULL);
	pthread_create(&tidread2,NULL,read2Thread,NULL);
	pthread_create(&tidwrite1,NULL,write1Thread,NULL);
	pthread_create(&tidwrite2,NULL,write2Thread,NULL);
	
	pthread_join(tidread1,NULL);
	pthread_join(tidread2,NULL);
	pthread_join(tidwrite1,NULL);
	pthread_join(tidwrite2,NULL);
	pthread_rwlock_destroy(&rwlock);
}
