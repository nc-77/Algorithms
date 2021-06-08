#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<int,int>mp[55];
set<int>p[55];
int num[55],a[55][10000+10];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int gs;
		cin>>gs;
		for(int j=1;j<=gs;j++)
		{
			int x;
			cin>>x;
			p[i].insert(x); 
			a[i][j]=x;
		}
	}
	int q;
	cin>>q;
	while(q--)
	{	flag.clear();
		int j1,j2,xt=0;
		cin>>j1>>j2;
		if(a[j1].size()<=a[j2].size)
		{
			for(int i=1;i<=a[j1].size();i++)
			{	if(p[j2].find(a[j2][i]))
				{ 
					if(mp[j2][a[j1][i]])
					xt++;
					flag[a[j1][i]]=1;
				} 
			}
		}
		else
		{
			for(int i=1;i<=ynum[j2];i++)
			{	if(!flag[a[j2][i]])
				{
				if(mp[j1][a[j2][i]])
				xt++;
				 } 
				
			}
		}
		int nt=num[j1]+num[j2]-xt;
		//cout<<xt<<" "<<num[j1]<<" "<<num[j2]<<endl;
		printf("%.2f%\n",xt*1.0/nt*100);
	}
}
