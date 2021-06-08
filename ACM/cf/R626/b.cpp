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
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=4e4+10;
int h[maxn],l[maxn];
ll sh[maxn],sl[maxn];
set<ll>s1,s2,s;
ll fun(int k,ll n,ll m)
{
    ll res=0;
    int sqr=sqrt(k);
    for(int i=1;i<=sqr;i++)
    {
        if(k%i==0)
        {
            ll x=i,y=k/i;
            res+=max(0ll,(m+1-y))*max((n+1-x),0ll);
            if(x!=y)
            {
                swap(x,y);
                res+=max(0ll,(m+1-y))*max((n+1-x),0ll);
            }
        }
    }
    res=res*sh[n]*sl[m];
    return res;
}
int main()
{   ios::sync_with_stdio(false);
   int n,m,k;
   cin>>n>>m>>k;
   int last=0;
   for(int i=1;i<=n;i++) 
	{
		cin>>h[i];
		if(!h[i]) 
		{   if((i-last-1)!=0)
			s1.insert(i-last-1);
			sh[i-last-1]++;
			last=i;
           
		}
		if(i==n&&h[i]==1) 
		{
			s1.insert(i-last);
		 	sh[i-last]++;
		 
		}
	}
	last=0;
    for(int i=1;i<=m;i++) 
	{
		cin>>l[i];
		if(!l[i]) 
		{   if((i-last-1)!=0)
			s2.insert(i-last-1);
			sl[i-last-1]++;
			last=i;
            
		}
		if(i==m&&l[i]==1) 
		{
			s2.insert(i-last);
		 	sl[i-last]++;
		}
	}
    ll ans=0;
    for(auto x:s1)
    {	
    	for(auto y:s2)
        {	
            ans+=fun(k,x,y);
        }
	}
        
    cout<<ans<<endl;
   //system("pause");
   return 0;
}

