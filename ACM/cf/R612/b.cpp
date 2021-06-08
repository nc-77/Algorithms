#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;
map<string,int>mp;
string a[2000];
int main()
{
	int n,m;
	cin>>n>>m;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
		
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{	s.clear();
			for(int k=0;k<m;k++)
			{
				if(a[i][k]!=a[j][k])
				{
					if(a[i][k]=='S'&&a[j][k]=='E'||a[j][k]=='S'&&a[i][k]=='E')
					s+='T';
					if(a[i][k]=='T'&&a[j][k]=='E'||a[j][k]=='T'&&a[i][k]=='E')
					s+='S';
					if(a[i][k]=='S'&&a[j][k]=='T'||a[j][k]=='S'&&a[i][k]=='T')
					s+='E';
				}
				if(a[i][k]==a[j][k])
				{
					s+=a[i][k];
				}
			}
			ans+=mp[s];
		}
	}
	cout<<ans/3<<endl;
}

