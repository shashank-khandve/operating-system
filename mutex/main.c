#include <pthread.h>
#include<stdio.h>
void
int main()
{
	pthread_t tidAdd,tidMul,tidDiv,tidSub;
	pthread_create(&tidAdd,NULL,Addthread,NULL);
	pthread_create(&tidMul,NULL,Multhread,NULL);
	pthread_create(&tidDiv,NULL,Divthread,NULL);
	pthread_create(&tidSub,NULL,Subthread,NULL);
	pthread_join(&tidSub);
}
