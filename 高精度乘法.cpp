#include<iostream>
using namespace std;
string s1,s2;
int a[101],b[101];/*s1,s2��ת��*/
int c[101];/*�߾���a�͸߾���b��ת��*/
void strtoint(string src,int des[])
{
	des[0]=src.length();
	for(int i=1;i<=des[0];i++)
	{
		des[i]=src[des[0]-i]-'0';
	}
}//��ת����
int main(){
	cin>>s1>>s2;
	//1.��λ����-��ת���ַ�ת���ͣ�
	strtoint(s1,a);
	strtoint(s2,b);
	int la=s1.size(),lb=s2.size();
	int lc=la+lb;
	//2.�������鳤�ȣ�
	//3.��λ��ӵó�c���飻
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
	//ȥ��ǰ��0��
	for(int i=lc;i>=1;i--)
	{
		cout<<c[i];
	}//4.�����ӡ
	return 0;
}
