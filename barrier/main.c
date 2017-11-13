#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_barrier_t barrierwait;
void *display(void *data)
{
	pthread_barrier_wait(&barrierwait);
	printf("i am in display\n");
}
void *reciever(void *data)
{
	sleep(3);
	pthread_barrier_wait(&barrierwait);
	printf("i am in reciever\n");
}
void *sensor(void *data)
{
	sleep(1);
	pthread_barrier_wait(&barrierwait);
	printf("i am in sensor\n");
}

int main()
{
	pthread_t sensortid,recievertid,displaytid;
	pthread_barrier_init(&barrierwait,0,2);
	pthread_create(&recievertid,NULL,reciever,NULL);
	pthread_create(&sensortid,NULL,sensor,NULL);
	pthread_create(&displaytid,NULL,display,NULL);
	pthread_join(sensortid,NULL);
	pthread_join(recievertid,NULL);
	pthread_join(displaytid,NULL);
	pthread_barrier_destroy(&barrierwait);
	return 0;
}

