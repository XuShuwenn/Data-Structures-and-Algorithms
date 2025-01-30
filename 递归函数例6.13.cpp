#include<iostream>
using namespace std;
const int max1 = 51;
int a[max1], n, m;
bool flag;
void sum(int n, int m)
{
	if (a[n] == m) flag = true;	 //利用全局变量falg传递结果
	else if (n == 1) return;	 //n=1作为递归边界，不再递归下去
	else                                            //进行两种选择
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
