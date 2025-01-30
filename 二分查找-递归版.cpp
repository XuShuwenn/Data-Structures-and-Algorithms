#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int> vec,int l,int r,int target)
{
	if(l>r)return -1;
	int mid=(l+r)/2;
	if(target==vec[mid])
		return mid;
	if(target>vec[mid])
		return binarysearch(vec,mid+1,r,target);
	if(target<vec[mid])
		return binarysearch(vec,l,mid-1,target);
}
int main()
{
	vector<int>vec{2,4,6,8,10};
	int tar;
	while(cin>>tar){
		cout<<binarysearch(vec,0,vec.size()-1,tar)+1<<endl;
	}
	return 0;
}

//算法库
//binary_search()二分搜索
//sort()快排
//min_element()查找最小值
//max_element()查找最大值
//reverse()反转
//
//string库
//string s=to_string(123.456) 数值转为string
//stod() string 转为double类型
//s.substr(m,n) 字符串截取:从下标m起，截取n个
