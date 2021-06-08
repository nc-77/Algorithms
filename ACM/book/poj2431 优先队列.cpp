#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n,l,p;
struct stop
{
    int dis;
    int fue;
}s[10000+5];
bool cmp(stop s1,stop s2)
{
	return s1.dis<s2.dis;
}
void solve()
{
	int tank=p,pos=0,ans=0;
	s[n].dis=l,s[n].fue=0; 
	priority_queue<int>que;
	for(int i=0;i<=n;i++)
	{
		int d=s[i].dis-pos;
		while(tank<d)
		{
			if(que.empty())
			{
				puts("-1");
				return;
			}
			tank=tank+que.top();
			//cout<<que.top()<<endl;
			que.pop();
			ans++;
		}
		tank-=d;
		pos=s[i].dis;
		que.push(s[i].fue);
	}
	cout<<ans<<endl;
}
int main()
{
	cin>>n;
	for(int i=n-1;i>=0;i--)
	{
		cin>>s[i].dis>>s[i].fue;
		
	}
	cin>>l>>p;
	for(int i=0;i<n;i++)
	{
		s[i].dis=l-s[i].dis;
		//cout<<s[i].dis<<" "<<s[i].fue<<endl;
	}
	sort(s,s+n,cmp);
	solve();
} 
