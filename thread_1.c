#include"header.h"

/* writing thread */
void* write_thread(void *p1)
{

	FILE *fp=fopen("data","w");  // open file in write mode

	/* using semaphore we need to sync */
	struct sembuf v1;
	v1.sem_num=1;   //checking 1st semaphore
	v1.sem_op=0;    // wait for 0 condition
	v1.sem_flg=0;

	printf("writing start..\n");

	semop(*(int*)p1,&v1,1); 

	semctl(*(int*)p1,1,SETVAL,10); // after entering into critical section , set 1st semaphore value as 10

	for(int i=1;i<11;i++)
	{
		fprintf(fp,"%d ",i);
		sleep(1);
	}
	fclose(fp);
	printf("writing completed..\n");

	semctl(*(int*)p1,1,SETVAL,0);   //after writing immediately making 1st sem. value as a 0 so that read_thread can read. 

	pthread_exit(0);    //coming out from writing thread.
}



/* reading thread */
void* read_thread(void *p2)
{

	FILE *fd=fopen("data","r");     // open file in read mode.

	struct sembuf v2;
	v2.sem_num=1;   //to check 1st semaphore value.
	v2.sem_op=0;
	v2.sem_flg=0;

	printf("reading starts..\n");

	int num;
	semop(*(int*)p2,&v2,1);
	/* entering into critical secton */
	for(int i=1;i<11;i++)
	{
		fscanf(fd,"%d",&num);   //everytime read data from file and put it into a veriable called num.
		printf("%d ",num);  //printing the num value.
	}
	printf("\nreading completed\n");

	semctl(*(int*)p2,1,SETVAL,0);   //after reading and printing make 1st semaphore value as a 0 , so that other thread can start execution.

	pthread_exit(0);    //coming out from from reading process.
}



void main()
{
	pthread_t t1,t2;

	int id=semget(4,3,IPC_CREAT|0644);      // creating semaphore set using semget function. upon success it will return an unique id.
	if(id<0)
	{
		perror("semget");
		return;
	}
	printf("id=%d\n",id);
	pthread_create(&t1,0,write_thread,&id);     
	pthread_create(&t2,0,read_thread,&id);

	pthread_exit(0);

}
