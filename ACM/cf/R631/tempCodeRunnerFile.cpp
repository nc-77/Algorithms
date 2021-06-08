#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll a[maxn],ans[maxn];
int main()
{
   int n,m;
   cin>>n>>m;
   ll sum=0;
   for(int i=1;i<=m;+i++) cin>>a[i],sum+=a[i];
   if(sum<n) {cout<<-1<<endl;return 0;}
   ll st=a[1];
   ans[1]=1,sum-=a[1];
   int flag=1;
   if(ans[1]+a[1]-1>n) flag=0;
   
   for(int i=2;i<=m;i++)
   {
      int temp=n-(sum-a[i])-st;
      st+=temp;
     ans[i]=st-a[i]+1;
     if(ans[i]<=ans[i-1])
     {
        ans[i]=ans[i-1]+1;
        if(ans[i]+a[i]-1>n) {flag=0;break;}
     }
     sum-=a[i];
      st=ans[i]+a[i]-1;
   }
   if(flag)
   for(int i=1;i<=m;i++)
   cout<<ans[i]<<" ";
   else puts("-1");
   //system("pause");
   return 0;
}
