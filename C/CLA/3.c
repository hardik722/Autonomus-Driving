#include<stdio.h>
#include<stdlib.h>
void main(int argc,char **argv)
{
int n1,n2,n3;
n1=atoi(argv[1]);
n2=atoi(argv[3]);
switch(argv[2][0])
{
case '+':n3=n1+n2;
	    printf("%d\n",n3);
	    break;
case '-':n3=n1-n2;
        printf("%d\n",n3);
        break;
case '*':n3=n1*n2;
		printf("%d\n",n3);
		break;
case '/':n3=n1/n2;
		printf("%d\n",n3);
		break;
}

}
