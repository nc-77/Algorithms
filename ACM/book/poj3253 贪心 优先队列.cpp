#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
int n;
ll l[20000+10],ans,l1,l2;
int main()
{
	cin>>n;
	priority_queue<ll,vector<ll>,greater<ll> >que;
	for(int i=0;i<n;i++)
	{
		cin>>l[i];
		que.push(l[i]);
	}
	while(n>1)
	{
		l1=que.top();
		que.pop();
		l2=que.top();
		que.pop();
		que.push(l1+l2);
		ans+=l1+l2;
		n--;
	}
	cout<<ans<<endl;
}
