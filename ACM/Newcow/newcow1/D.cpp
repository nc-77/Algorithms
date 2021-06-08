#include<bits/stdc++.h>
using namespace std;
int vis[100000+10];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x;
		cin>>x;
		vis[x]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cout<<i<<endl;
			break;
		}
	}
}
