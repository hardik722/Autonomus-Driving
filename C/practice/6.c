#include<stdio.h>
void main()
{
int i,j,num,m,n;
printf("enter num..\n");
scanf("%d",&num);
//////////////////////////////////////
printf("before reversing..\n");
for(i=31;i>=0;i--)
printf("%d",num>>i&1);
printf("\n");
/////////////////////////////////
for(i=31,j=0;i>j;i--,j++)
{
m=num>>i&1;
n=num>>j&1;

if(m!=n)
{
num=num^1<<i;
num=num^1<<j;
}

}
//////////////////////////////
printf("after reversing...\n");
for(i=31;i>=0;i--)
printf("%d",num>>i&1);
printf("\n");

}
