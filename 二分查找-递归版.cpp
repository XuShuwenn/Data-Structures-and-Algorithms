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

//�㷨��
//binary_search()��������
//sort()����
//min_element()������Сֵ
//max_element()�������ֵ
//reverse()��ת
//
//string��
//string s=to_string(123.456) ��ֵתΪstring
//stod() string תΪdouble����
//s.substr(m,n) �ַ�����ȡ:���±�m�𣬽�ȡn��
