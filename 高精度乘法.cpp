#include<iostream>
using namespace std;
string s1,s2;
int a[101],b[101];/*s1,s2的转换*/
int c[101];/*高精度a和高精度b的转换*/
void strtoint(string src,int des[])
{
	des[0]=src.length();
	for(int i=1;i<=des[0];i++)
	{
		des[i]=src[des[0]-i]-'0';
	}
}//反转函数
int main(){
	cin>>s1>>s2;
	//1.个位对齐-反转，字符转整型；
	strtoint(s1,a);
	strtoint(s2,b);
	int la=s1.size(),lb=s2.size();
	int lc=la+lb;
	//2.计算数组长度；
	//3.对位相加得出c数组；
	for(int i=1;i<=la;i++)
	{
		for(int j=1;j<=lb;j++)
		{
			c[i+j-1]+=a[i]*b[j];
			c[i+j]+=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
	}
	while((c[lc]==0)&&lc>0)lc--;
	//去除前导0；
	for(int i=lc;i>=1;i--)
	{
		cout<<c[i];
	}//4.倒序打印
	return 0;
}
