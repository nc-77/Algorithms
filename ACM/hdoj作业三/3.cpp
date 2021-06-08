#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e3+10;
int vis[maxn];
struct node
{
	int ddl,num;
}s[maxn];
bool cmp(node x,node y)
{
	if(x.num>y.num) return true;
	else if(x.num==y.num) return x.ddl<y.ddl;
	return false;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {	set0(s),set0(vis);
    	int n;
    	cin>>n;
    	int ddl=0,ans=0;
    	for(int i=1;i<=n;i++)
    	{
    		cin>>s[i].ddl;
    		ddl=max(ddl,s[i].ddl);
		}
		for(int i=1;i<=n;i++) cin>>s[i].num,ans+=s[i].num;
		sort(s+1,s+n+1,cmp);
		int d=0,flag;
		for(int i=1;i<=n;i++)
		{	//debug(vis[4]);
			flag=1;
			for(int k=s[i].ddl;k<=ddl;k++)
			if(vis[k]==k)
			{
				flag=0;
				break;
			}
			if(vis[s[i].ddl]<s[i].ddl&&flag)
			{	//debug(i);
				//debug(s[i].ddl),debug(vis[s[i].ddl]);
				d+=s[i].num;
				for(int j=s[i].ddl;j<=ddl;j++)
				vis[j]++;
			}
		}
		cout<<ans-d<<endl;
	}
}
