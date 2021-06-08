#include<bits/stdc++.h>
#define ll long long
using namespace std;
int vis[200000+10];

int main()
{
	int n,a,b,k,ans=0,num=0;
	cin>>n>>a>>b>>k;
	while(n--)
	{
		int x;
		cin>>x;
		if(x%(a+b)==0) 
		{
		
			vis[num++]=a+b;
		}
		else if(x%(a+b)<=a) ans++;
		else vis[num++]=x%(a+b);
		
		
	}
	//cout<<ans<<endl;
	sort(vis,vis+num);
		for(int i=0;i<num;i++)
		{	if(k<=0) break;
			int need=vis[i]/a;
			if(vis[i]%a==0) need--;
			if(k>=need)
			{
				k-=need;
				ans++;
				//cout<<k<<endl;
			}
		}
		cout<<ans<<endl;
	
}
