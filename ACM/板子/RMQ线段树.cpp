#define ls id*2
#define rs id*2+1
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
