#include<iostream>//（高精度/低精度）
using namespace std;
string s;
int a[101],r;//余数r
long long b;
int c[101];
int main(){
	cin>>s;
	cin>>b;
	int ls=s.length();
	for(int i=1;i<=ls;i++)
	{
		a[i]=s[i-1]-'0';
	}
	for(int i=1;i<=ls;i++)
	{
		c[i]=(r*10+a[i])/b;
		r=(r*10+a[i])%b;
	}
	int lc=1;
	while(c[lc]==0&&lc<ls)lc++;
	for(int i=lc;i<=ls;i++)
	{
		cout<<c[i];
	}
	cout<<endl<<r;
	return 0;
}
