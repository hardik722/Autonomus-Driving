#include<stdio.h>
void main()
{
int num,r,sum=0;
printf("enter the num= ");
scanf(" %d",&num);

while(num>0)
{
r=num%10;
sum=sum+r;
num=num/10;
}

printf(" sum=%d\n",sum);
}
