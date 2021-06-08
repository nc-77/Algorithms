#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
#define ls id*2
#define rs id*2+1
using namespace std;
const int maxn=2e5+10;
struct node
{
	int l,r,max;
}t[4*maxn];
int a[maxn],n;
void build(int id,int l,int r)
{
	t[id].l=l,t[id].r=r;
	if(l==r) 
	{
		t[id].max=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[id].max=max(t[ls].max,t[rs].max);
}
void change(int id,int l,int k)
{
	if(l==t[id].l&&l==t[id].r) 
	{
		t[id].max=k;
		return;
	}
	int mid=(t[id].l+t[id].r)/2;
	if(l<=mid) change(ls,l,k);
	if(l>mid) change(rs,l,k);
	t[id].max=max(t[ls].max,t[rs].max); 
}
int query(int id,int l,int r)
{	int v1=0,v2=0; 
	if(l<=t[id].l&&r>=t[id].r) return t[id].max;
	int mid=(t[id].l+t[id].r)/2;
	if(l<=mid) v1=query(ls,l,r);
	if(r>mid) v2=query(rs,l,r);
	return max(v1,v2);
}
int main()
{	ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    int m;
    while(cin>>n>>m)
    {	set0(t);
    	
    	for(int i=1;i<=n;i++)
	    cin>>a[i];
	    build(1,1,n);
	    char op;
	    while(m--)
	    {	
	    	int x,y;
	    	cin>>op>>x>>y;
	    	if(op=='Q')
	    	{
	    		cout<<query(1,x,y)<<endl;
			}
			else
			change(1,x,y);
		}
	}
    
}

