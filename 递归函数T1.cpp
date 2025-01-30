#include<iostream>
#include<stdio.h>
#include<cmath>
int n;
float fx(float y,int m)
{
	return sqrt(m+y);
}
int main()
{	
	float x;
	scanf("%f %d",&x,&n);
	float f=x;
	for(int i=1;i<=n;i++)
	{
		f=fx(f,i);
	}
	printf("%f\n",f);
	return 0;
}
