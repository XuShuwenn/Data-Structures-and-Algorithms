#include<iostream>
using namespace std;
string s1,s2;
int a[101],b[101];//s1,s2��ת��
int c[101];//�߾���
void strtoint(string src,int des[])
{
	des[0]=src.length();
	for(int i=1;i<=des[0];i++)
	{
		des[i]=src[des[0]-i]-'0';
	}
}//��ת����
int main()
{
	cin>>s1>>s2;
	strtoint(s1,a);
	strtoint(s2,b);
	//��ת
	int la=s1.size(),lb=s2.size();
	int lc=max(la,lb)+1;
	//�����鳤��
	for(int i=1;i<=lc;i++)
	{
		if(a[i]<b[i]){
			a[i+1]--;
			a[i]=a[i]+10;
		}
		c[i]=a[i]-b[i];
	}
	while((c[lc]==0)&&lc>0)lc--;
	for(int i=lc;i>=1;i--)
	{
		cout<<c[i];
	}
	return 0;
}
