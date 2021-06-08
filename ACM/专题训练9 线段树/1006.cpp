#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
#define ls id*2
#define rs id*2+1
using namespace std;
const int maxn=2e5+10;
int cnt,ans[maxn];
map<int,int>mp;
struct stu
{
	int id,pow,loy,l,r;
}s[maxn];
struct node
{
	int l,r,mx;
}t[maxn];
vector<int>g[maxn];
bool cmp(stu x,stu y)
{
	if(x.pow>y.pow) return true;
	else if(x.pow==y.pow) return x.id<y.id;
	return false;
}
void build(int id,int l,int r)
{	t[id].l=l,t[id].r=r;
	if(l==r) 
	{
		t[id].mx=-1;
		return;
	}
	int mid=(l+r)/2;
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[id].mx=max(t[ls].mx,t[rs].mx);
}
void dfs(int x)
{
	s[x].l=cnt;
	for(int i=0;i<g[x].size();i++)
	{
		cnt++;
		dfs(g[x][i]);
	}
	s[x].r=cnt;
}
int query(int id,int l,int r)
{	int ret=-1;
	if(l<=t[id].l&&r>=t[id].r)
	{
		return t[id].mx;
	}	
	int mid=(t[id].l+t[id].r)/2;
	if(l<=mid) ret=max(ret,query(ls,l,r));
	if(r>mid) ret=max(ret,query(rs,l,r));
	return ret;
}
void change(int id,int x,int k)
{
	if(x==t[id].l&&x==t[id].r)
	{
		t[id].mx=k;
		return;
	}
	int mid=(t[id].l+t[id].r)/2;
	if(x<=mid) change(ls,x,k);
	else change(rs,x,k);
	t[id].mx=max(t[ls].mx,t[rs].mx);
}
int main()
{	ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {	mp.clear();
    	int n,m;
    	cin>>n>>m;
    	for(int i=0;i<=n;i++) g[i].clear();
    	set0(s),set0(t),set0(ans);
    	for(int i=1;i<=n-1;i++)
    	{
    		int x;
    		cin>>x;
    		g[x].push_back(i);
    		cin>>s[i].loy>>s[i].pow;
    		s[i].id=i;
    		mp[s[i].loy]=i;
		}
		
		build(1,1,n-1);
		cnt=0;
		dfs(0);
		//for(int i=1;i<n;i++) debug(g[i].size()),debug(s[i].l),debug(s[i].r);
		sort(s+1,s+n,cmp);
		for(int i=1;i<n;i++)
		{	//debug(s[i].l),debug(s[i].r);
			int t=query(1,s[i].l,s[i].r);
			//debug(t);
			if(t==-1) ans[s[i].id]=-1;
			else ans[s[i].id]=mp[t];
			change(1,s[i].l,s[i].loy);
		}
		while(m--)
		{	int q;
			cin>>q;
			cout<<ans[q]<<endl;
		}
	}
}

