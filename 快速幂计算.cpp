#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
ll quickpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b%2==1)res*=a;
	
	a*=a;//±¶Ôö
	b/=2;//ÓÒÒÆÒ»Î»
	}
	return res;
}
int main()
{
	int a,b;
	while(cin>>a>>b){
		cout<<quickpow(a,b)<<endl;
	} 
	return 0;
}
