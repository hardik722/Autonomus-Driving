#include<iostream>
using namespace std;
int main()
{
int a[3][2]={{10,20},{30,40},{50,60}};
int (*p)[2]=a;

for(int i=0;i<3;i++)
{
for(int j=0;j<2;j++)
cout<<p[i][j]<<" ";
cout<<"\n";
}

}

