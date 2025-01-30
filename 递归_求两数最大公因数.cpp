#include<iostream>
int gcd(int m, int n)
{
	if(m%n==0) return n;
	else return gcd(n,m%n);
}
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	printf("gcd=%d\n", gcd(m,n)); 
	return 0;
}
