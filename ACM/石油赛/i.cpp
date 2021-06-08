#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e3+10;
int par[maxn];
int high[maxn];//Ê÷µÄ¸ß¶È
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		par[i]=i;
		high[i]=0;
	}
} 
int find(int x)
{
	if(par[x]==x)
	return x;
	else
	return par[x]=find(par[x]);
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(high[x]<high[y])
	par[x]=y;
	else 
	{
		par[y]=x;
		if(high[x]==high[y]) high[x]++;
	}
}
struct node
{
	ll x,y,z,v;
}s[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    init(n);
    for(int i=1;i<=n;i++)
    cin>>s[i].x>>s[i].y>>s[i].z>>s[i].v;
    for(int i=1;i<=n;i++)
    	for(int j=i+1;j<=n;j++)
    	{	if(fabs(s[i].v-s[j].v)>m) continue;
    		if(s[j].x==s[i].x&&s[i].y==s[j].y&&fabs(s[i].z-s[j].z)==1)
    		unite(i,j);
    		else if(s[j].x==s[i].x&&s[i].y==s[j].y&&fabs(s[i].z-s[j].z)==1)
    		unite(i,j);
    		else if(s[j].x==s[i].x&&fabs(s[i].y-s[j].y)==1&&s[i].z==s[j].z)
    		unite(i,j);
    		else if(fabs(s[i].x-s[j].x)==1&&s[i].y==s[j].y&&s[i].z==s[j].z)
    		unite(i,j);
    		else if(s[j].x==s[i].x&&s[i].y==s[j].y&&s[i].z==s[j].z)
    		unite(i,j);
		}
		int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i==par[i]) ans++;
	}
	cout<<ans<<endl;
}

