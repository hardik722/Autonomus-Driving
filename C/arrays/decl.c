#include<stdio.h>
void main()
{
int a[5]={10,20,30,40,50};
 int ele,i;

ele=sizeof(a)/sizeof(a[5]);
printf("%d\n",ele);

for(i=0;i<ele;i++)
printf("%d ",a[i]);

printf("\n");

for(i=ele-1;i>=0;i--)
printf("%d ",a[i]);

printf("\n");

}
