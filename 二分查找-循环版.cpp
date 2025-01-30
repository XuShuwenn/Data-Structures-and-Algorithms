#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int> vec,int target)
{
	int l=0,r=vec.size()-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(target==vec[mid])
		{
			return mid;
		}
		else if(target>vec[mid])
		{
			l=mid+1;
		}
		else r=mid-1;
	}
	return -1;
}
int main()
{
	vector<int>vec{2,4,6,8,10};
	int tar;
	while(cin>>tar){
		cout<<binarysearch(vec,tar)+1<<endl;
	}
	return 0;
}
