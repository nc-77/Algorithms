#define ls id<<1
#define rs id<<1|1
int n,m,a[maxn];
struct tree
{
	int l,r,sum;
	int tag;
}t[maxn*4]; 
void pushdown(int id)
{	
	t[ls].sum+=(t[ls].r-t[ls].r+1)*t[id].tag;
	t[rs].sum+=(t[rs].r-t[rs].r+1)*t[id].tag;
	t[ls].tag+=t[id].tag;
	t[rs].tag+=t[id].tag;
	t[id].tag=0;
}
void build(int id,int l,int r)
{
	t[id].l=l,t[id].r=r,t[id].tag=0;
	if(l==r) 
	{
		t[id].sum=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[id].sum=t[ls].sum+t[rs].sum;
} 
void add(int id,int l,int r,int p)
{
	if(l<=t[id].l&&r>=t[id].r) 
	{
		t[id].sum+=(t[id].r-t[id].l+1)*p;
		t[id].tag+=p;
		return;
	}
	if(t[id].tag) pushdown(id);
	int mid=(t[id].l+t[id].r)/2;
	if(l<=mid) change(ls,l,r,p);
	if(r>mid) change(rs,l,r,p);
	t[id].sum=t[ls].sum+t[rs].sum;
}
int query(int id,int l,int r)
{
	int res=0;
	if(l<=t[id].l&&r>=t[id].r)
	return t[id].sum;
	if(t[id].tag) pushdown(id);
	int mid=(t[id].l+t[id].r)/2;
	if(l<=mid) res+=query(ls,l,r);
	if(r>mid) res+=query(rs,l,r);
	return res;
}
