#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
#define ls id*2
#define rs id*2+1
using namespace std;
const int maxn=2e5+10;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
struct node
{
	int lmax,rmax,zmax,l,r,tag;
}t[maxn*4];
void pushup(int id)
{
	t[id].lmax=t[ls].lmax;
	t[id].rmax=t[rs].rmax;
	t[id].zmax=max(t[ls].zmax,t[rs].zmax);
	if(t[ls].lmax==t[ls].r-t[ls].l+1) t[id].lmax+=t[rs].lmax;
	if(t[rs].rmax==t[rs].r-t[rs].l+1) t[id].rmax+=t[ls].rmax;
	t[id].zmax=max(t[id].zmax,t[ls].rmax+t[rs].lmax);

}
void pushdown(int id)
{
	t[ls].tag=t[rs].tag=t[id].tag;
	if(t[id].tag==1)
	t[ls].lmax=t[ls].rmax=t[ls].zmax=t[rs].lmax=t[rs].rmax=t[rs].zmax=0;
	else
	{
		t[ls].lmax=t[ls].rmax=t[ls].zmax=t[ls].r-t[ls].l+1;
		t[rs].lmax=t[rs].rmax=t[rs].zmax=t[rs].r-t[rs].l+1;
	}
	t[id].tag=0;
	
}
void build(int id,int l,int r)
{	t[id].l=l,t[id].r=r,t[id].tag=0;
	if(l==r) 
	{
		t[id].lmax=t[id].rmax=t[id].zmax=1;
		return;
	}
	int mid=(l+r)/2;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(id);
}
void change(int id,int l,int r,int k)
{
	if(l<=t[id].l&&r>=t[id].r) 
	{	t[id].tag=k;
		if(k==-1)
		{
			t[id].lmax=t[id].rmax=t[id].zmax=t[id].r-t[id].l+1;
			return;
		}
		if(k==1)
		{
			t[id].lmax=t[id].rmax=t[id].zmax=0;
			return;
		}
	}
	int mid=(t[id].l+t[id].r)/2;
	if(t[id].tag) pushdown(id);
	if(l<=mid) change(ls,l,r,k);
	if(r>mid) change(rs,l,r,k);
	pushup(id);
}
int query(int id,int num)
{	
	if(t[id].tag) pushdown(id);
	if(t[ls].zmax>=num) return query(ls,num);
	else if(t[ls].rmax+t[rs].lmax>=num) return t[ls].r-t[ls].rmax+1;
	else if(t[rs].zmax>=num) return query(rs,num); 
	else return -1;
	
}
int main()
{	int n,m;
	//ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    	while(cin>>n>>m)
    	{
    		build(1,1,n);
		int x,y,op;
    	while(m--)
    	{
    		cin>>op;
    		if(op==1) 
    		{	read(x);
				
    			if(t[1].zmax>=x)
				{
					int ans=query(1,x);
					cout<<ans<<endl;
					change(1,ans,ans+x-1,1);
				}
				else puts("0");
    	
			}
    		else 
    		{
    			read(x);read(y);
    			change(1,x,x+y-1,-1);
			}
    		
		}
		}
    	
	
}

