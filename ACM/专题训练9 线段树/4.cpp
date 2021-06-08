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
	int l,r,f,tag,sum;
}t[maxn*4];
void build(int id,int l,int r)
{
	t[id].l=l,t[id].r=r,t[id].f=1,t[id].tag=0;
	if(l==r) 
	{
		t[id].sum=1;
		return;
	}
	int mid=(l+r)/2;
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[id].sum=t[ls].sum+t[rs].sum;

}
void pushdown(int id)
{
	t[id].tag=0;
	t[ls].sum=(t[ls].r-t[ls].l+1)*t[id].f;
	t[rs].sum=(t[rs].r-t[rs].l+1)*t[id].f;
	t[ls].tag=t[rs].tag=1;
	t[ls].f=t[rs].f=t[id].f;
}
void change(int id,int l,int r,int k)
{
	if(l<=t[id].l&&r>=t[id].r) 
	{
		t[id].tag=1;
		t[id].f=k;
		t[id].sum=k*(t[id].r-t[id].l+1);
		return;
	}
	if(t[id].tag)  pushdown(id);
	int mid=(t[id].l+t[id].r)/2;
	if(l<=mid) change(ls,l,r,k);
	if(r>mid) change(rs,l,r,k);
	t[id].sum=t[ls].sum+t[rs].sum;
}
int main()
{
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
	for(int i=1;i<=T;i++)
	{	set0(t);
		
		int n;
		cin>>n;
		build(1,1,n);
		int q;
		cin>>q;
		while(q--)
		{
			int x,y,k;
			cin>>x>>y>>k;
			change(1,x,y,k);
			
		}
		cout<<"Case "<<i<<": The total value of the hook is "<<t[1].sum<<"."<<endl;
	}
}

