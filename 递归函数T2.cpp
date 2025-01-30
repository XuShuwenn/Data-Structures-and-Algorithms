#include<iostream>
#include<cmath>
#include<stdio.h>
float x,n;
float fx(float y, float m)
{
	return (x/(m+y));
}
int main()
{
	scanf("%f %f",&x,&n);
	float f;
	f=x;
	for(int i=1;i<=n;i++)
	{
		f=fx(f,i);
	}
	printf("%f",f);
	return 0;
}
