#include<iostream>
using namespace std;
const int max1 = 51;
int a[max1], n, m;
bool flag;
void sum(int n, int m)
{
	if (a[n] == m) flag = true;	 //����ȫ�ֱ���falg���ݽ��
	else if (n == 1) return;	 //n=1��Ϊ�ݹ�߽磬���ٵݹ���ȥ
	else                                            //��������ѡ��
	{
		sum(n - 1, m - a[n]);
		sum(n - 1, m);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) 
	{
		cin >> a[i];
	}
	cin >> m;
	flag = false;
	sum(n, m);
	if (flag) cout << "YES" << endl;
	else  cout << "NO" << endl;
	return 0;
}
