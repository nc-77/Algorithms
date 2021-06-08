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
    int flag=1;
   for(int i=1;i<=m;+i++) 
   {cin>>a[i],sum+=a[i];
   if(a[i]+i-1>n) flag=0;}
   if(sum<n) flag=0;
   ll last=a[1],now=1;
   ans[1]=1,sum-=a[1];
   for(int i=2;i<=m;i++)
   {
      if(sum+now>=n) 
      now++;
      else now=n-sum+1;
      ans[i]=now;
      sum-=a[i];
      last=now+a[i]-1;
   }
   if(flag)
   for(int i=1;i<=m;i++)
   cout<<ans[i]<<" ";
   else puts("-1");
   //system("pause");
   return 0;
}
