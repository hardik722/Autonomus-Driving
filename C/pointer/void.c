#include<stdio.h>
void main()
{
char ch='a';
int i=258;
float f=23.5;
void *p;

p=&ch;
printf("%c\n",*(char*)p);

p=&i;
printf("%d\n",*(int*)p);


p=&f;
printf("%f\n",*(float*)p);



}
