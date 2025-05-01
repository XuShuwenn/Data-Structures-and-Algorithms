#include <iostream>
#include <algorithm>  
using namespace std;
int a[100000];
int n;
int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++) 
	{
        cin >> a[i];
    }
    int max_sum = a[0];   // 记录全局最大子区间和，初始值设为第一个元素
    int current_sum = a[0];  // 记录当前子区间和
    for (int i = 1; i < n; i++) 
	{
        current_sum = max(a[i], current_sum + a[i]);
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << endl;
    return 0;
}
