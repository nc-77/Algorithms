#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
#define int long long
struct node
{
    int num,sum;
}bit[maxn];
int a[maxn];int n;
int sum(int i,int flag)
{
	int s=0;
    if(flag)
	while(i>0)
	{
		s+=bit[i].num;
		i-=i&-i;
	}
    else
    {
        while(i>0)
        {
            s+=bit[i].sum;
            i-=i&-i;
        }
    }
    
	return s;
}
void add(int i,int x,int flag)
{
    if(flag)
	while(i<=n)
	{
		bit[i].num+=x;
		i+=i&-i;
	}
    else
    {
        while(i<=n)
        {
            bit[i].sum+=x;
            i+=i&-i;
        }
    }
    
}
signed main()
{
   
   cin>>n;
   int ans=0;
   int s=0;
   for(int i=1;i<=n;i++) 
   {
       cin>>a[i];
        ans+=(i-1-sum(a[i],1))*a[i]+(s-sum(a[i],0));
        add(a[i],1,1);
        add(a[i],a[i],0);
        s+=a[i];
        //debug(ans);
   }
   cout<<ans<<endl;
   //system("pause");
   return 0;
}
