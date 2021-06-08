#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) for(int i=1;i<=t;i++) x[i]=0
#define ll long long
#define inf 0x3f3f3f3f
#define ls id*2
#define rs id*2+1
using namespace std;
const int maxn=1e5+10;
int t;
set<int>s;
struct node
{
	int l,r,sum,tag;
}tree[maxn*4];
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r,tree[id].sum=1;
	if(l==r) 
	{
		tree[id].sum=1;
		return;
	}
	int mid=(l+r)/2;
	build(ls,l,mid);
	build(rs,mid+1,r);
	
}
void pushdown(int id)
{	int c=tree[id].tag;
	
	tree[ls].sum=c;
	tree[rs].sum=c;
	tree[id].tag=0;
	tree[ls].tag=tree[rs].tag=c;
}
void change(int id,int l,int r,int c)
{	
	if(l<=tree[id].l&&r>=tree[id].r)
	{	
		tree[id].sum=c;
		tree[id].tag=c;
		return;
	}
	if(tree[id].tag) pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(l<=mid) change(ls,l,r,c);
	if(r>mid) change(rs,l,r,c);
	tree[id].sum=tree[ls].sum|tree[rs].sum;
}
int query(int id,int l,int r)
{
	int res=0;
	if(l<=tree[id].l&&r>=tree[id].r)
	{
		return tree[id].sum;
	}
	
	if(tree[id].tag) pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(l<=mid) res|=query(ls,l,r);
	if(r>mid) res|=query(rs,l,r);
	return res;
}
int main()
{	ios::sync_with_stdio(false);
    int l,o;
    while(cin>>l>>t>>o)
    {
    	build(1,1,l);
	    while(o--)
	    {
	    	char op[10];
	    	cin>>op;
	    	int a,b,c;
	    	if(op[0]=='C')
	    	{
	    		
	    		cin>>a>>b>>c;
	    		if(a>b) swap(a,b);
	    		c=pow(2,c-1);
	    		change(1,a,b,c);
			}
			if(op[0]=='P')
			{
				cin>>a>>b;
				if(a>b) swap(a,b);
				
				int sum=query(1,a,b);
				int ans=0;
				//debug(sum);
				while(sum)
				{
					if(sum&1) ans++;
					sum=sum>>1;
				}
				cout<<ans<<endl;
			}
		}
	}
    
}

