#include<bits/stdc++.h>
using namespace std;
int a[100000+10];
int main()
{
	int n,num=0;
	cin>>n;
	int x;
	cin>>x;
	a[num++]=x;
	n--;
	while(n--)
	{
		cin>>x;
		int find=upper_bound(a,a+num,x)-a;
		if(find>=0&&find<num) a[find]=x;
		else a[num++]=x; 
	}
	cout<<num<<endl;
}
