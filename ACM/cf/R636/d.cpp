#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=4e5+10;
int a[maxn],l[maxn],r[maxn],sum[maxn];
map<ll,ll>mp;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
#define ls id<<1
#define rs id<<1|1
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
		t[id].sum=0;
		return;
	}
	int mid=(l+r)/2;
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[id].sum=t[ls].sum+t[rs].sum;
} 
void change(int id,int l,int r,int p)
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
signed main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,k;
       read(n),read(k);
       for(int i=1;i<=n;i++) 
       {
           read(a[i]);
           
       }
       mp.clear();
      build(1,1,2*k);
      
       for(int i=1;i<=n/2;i++)
       {
           l[i]=min(a[i],a[n-i+1])+1;
           r[i]=max(a[i],a[n-i+1])+k;
           
           change(1,l[i],r[i],1);
        
           mp[a[i]+a[n-i+1]]++;
       }
       int ans=0;
       for(int i=1;i<=2*k;i++)
       {

           ans=max(ans,query(1,i,i)+mp[i]);
       }
       
        cout<<n-ans<<endl;
   }
   //system("pause");
   return 0;
}
