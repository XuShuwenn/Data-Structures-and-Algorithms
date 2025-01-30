#include<iostream>
using namespace std;
int f[100][100];
bool v[100][100];
int main()
{
	int n,m,cx,cy;
	cin>>n>>m>>cx>>cy;
	v[n][m]=1;
	int dx[8]={1,1,-1,-1,2,2,-2,-2};
	int dy[8]={2,-2,2,-2,1,-1,1,-1};
	for(int i=0;i<8;i++)
	{
		int bx=cx+dx[i];
		int by=cy+dy[i];
		v[bx][by]=1;
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=f[i-1][0];
		if(v[i][0]==1)f[i][0]=0;
	}
	for(int j=1;j<=n;j++)
	{
		f[0][j]=f[0][j-1];
		if(v[0][j]==1)f[0][j]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=f[i-1][j]+f[i][j-1];
			if(v[i][j]==1)f[i][j]=0;
		}
	}
	cout<<f[n][m];
	return 0;
}
