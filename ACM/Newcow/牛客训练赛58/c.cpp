#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define mst(a,b) memset((a),(b),sizeof(a))
#define PII pair<int,int>
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=25;
int n,m,k;
ll a[maxn][maxn],sum;
ll r[maxn],c[maxn],ans,vr[maxn],vc[maxn],s[maxn];
vector<int>g;
sturct node
{
	int step,c,ans;
}cur,nex;
void bfs(int st)
{	ll ans=0;
	queue<node>que;
	que.push({1,st});
	while(!que.empty())
	{
	 cur=que.front();
		que.pop();
		if(cur.step>k) break;
		if(cur.step==k) ans=max(ans,cur.ans);
		ll maxx=0;
		for(int i=1;i<=n;i++)
		{	if(vr[i]) continue;
			maxx=max(maxx,x[i]);
			
		}
		for(int i=1;i<=m;i++)  
		{	if(vc[i]) continue;
			maxx=max(maxx,y[i]);
		}
		for(int i=1;i<=n;i++) 
		{
			if(x[i]==maxx)
			{	nex.ans=cur.ans;
				vr[i]=1;
				nex.c=i;
				nex.step=cur.step+1;
				for(int j=1;j<=m;j++)
				if(!vc[j])
				nex.ans+=a[i][j];
				que.push(nex);
			}
		} 
		for(int i=1;i<=m;i++) 
		{
			if(y[i]==maxx)
			{	
				vc[i]=1;
				nex.c=i;
				nex.step=cur.step+1;
				for(int j=1;j<=n;j++)
				if(!vr[j])
				nex.ans+=cur.ans+a[j][i];
				que.push(nex);
			}
		} 
		
	}
	return ans;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) 
	{
		read(a[i][j]),sum+=a[i][j],x[i]+=a[i][j],y[j]+=a[i][j];
		
	}

	
	if(k>=min(n,m))
	{
		cout<<sum<<endl;
	}
	else
	{
	
		
	}
	return 0;
}
