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
int n,q,a[maxn];
struct node
{
	int lmax,rmax,zmax,l,r,ans;
}t[maxn*4];
void pushup(int id)
{
 t[id].lmax=t[ls].lmax;
t[id].rmax=t[rs].rmax;
	t[id].zmax=max(t[ls].zmax,t[rs].zmax);
	if(a[t[ls].r]<a[t[rs].l]) 
	{
		if(t[ls].lmax==t[ls].r-t[ls].l+1) t[id].lmax+=t[rs].lmax;
		if(t[rs].rmax==t[rs].r-t[rs].l+1) t[id].rmax+=t[ls].rmax;
		t[id].zmax=max(t[id].zmax,t[ls].rmax+t[rs].lmax);
	}
}
void build(int id,int l,int r)
{	t[id].l=l,t[id].r=r;
	if(l==r) 
	{
		t[id].lmax=t[id].rmax=t[id].ans=t[id].zmax=1;
		return;
	}
	int mid=(l+r)/2;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(id);
}
void change(int id,int x,int k)
{
	if(t[id].l==t[id].r&&t[id].l==x)
	return;
	int mid=(t[id].l+t[id].r)/2;
	if(x<=mid) change(ls,x,k);
	if(x>mid) change(rs,x,k);
	pushup(id); 
}
int query(int id,int l,int r)
{	int res=0;
	if(l<=t[id].l&&r>=t[id].r) return t[id].zmax;
	int mid=(t[id].l+t[id].r)/2;
	if(l<=mid) res=query(ls,l,r);
	if(r>mid) res=max(res,query(rs,l,r));
	if(a[mid]<a[mid+1])
	res=max(res,min(t[ls].rmax,mid-l+1)+min(t[rs].lmax,r-mid));
	
	return res;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
    	set0(t),set0(a);
    	cin>>n>>q;
    	for(int i=1;i<=n;i++)
    	cin>>a[i];
    	build(1,1,n);
    	
    	char op[2];
		int x,y;
    	while(q--)
    	{
    		scanf("%s",op);
    		scanf("%d%d",&x,&y);
    		
    		if(op[0]=='Q') 
    		cout<<query(1,x+1,y+1)<<endl;
    		else 
    		{
    			a[x+1]=y;
    			change(1,x+1,y);
    			
			}
    		
		}
	}
}

