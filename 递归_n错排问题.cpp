#include<iostream>
using namespace std;
int main()
{
	int f[10001];
	f[1]=0;
	f[2]=1;
	int n;
	cin>>n;
	for(int i=3;i<=n;i++)
	{
		f[i]=(i-1)*(f[i-1]+f[i-2]);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<f[i]<<" ";
	}
	return 0;
}
