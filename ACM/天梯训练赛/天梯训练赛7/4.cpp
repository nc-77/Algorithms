#include<bits/stdc++.h>
#define ll long long
using namespace std;
int vis[1000000];
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int k;
		cin>>k;
		for(int i=0;i<k;i++)
		{
			int x;
			cin>>x;
			if(k>=2)
			vis[x]=1;
		}
	}
	int q,sum=0;
	cin>>q;
	while(q--)
	{	
		int y;
		cin>>y;
		if(vis[y]==0) 
		{	sum++;
			if(sum==1)
			printf("%05d",y);
			else
			printf(" %05d",y);
			vis[y]=1;
		 } 
		 
	}
	if(sum==0) cout<<"No one is handsome"<<endl;
}
