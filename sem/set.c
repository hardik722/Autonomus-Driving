#include"header.h"
void main(int argc,char **argv)
{
if(argc!=3)
{
printf("usage: ./get sem_num\n");
return;
}
int id;
id=semget(7,4,IPC_CREAT|0644);
if(id<0)
{
perror("semget");
return;
}
printf("id=%d\n",id);
/*******************************************/
int r;
r=semctl(id,atoi(argv[1]),SETVAL,atoi(argv[2]));
if(r<0)
{
perror("semctl");
return;
}

}
