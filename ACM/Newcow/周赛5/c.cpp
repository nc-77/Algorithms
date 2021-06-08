#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn];
int k,n;
int fac(int x){
    
    if((x-1)%(k-1)==0) return (x-1)/(k-1);
    else return (x-1)/(k-1)+1;
}
int main()
{
   //ios::sync_with_stdio(false);
   
   cin>>n>>k;
   int st=0;
   for(int i=1;i<=n;i++){
       cin>>a[i];
       if(a[i]==1) st=i;
   }
   int ans=inf;
   int l,r;
   for(int i=0;i<=min(st-1,k-1);i++)
   {
       l=max(st-i,1);
       r=min(n-(st+k-1-i)+1,n);
       //debug(l),debug(r);
       ans=min(ans,fac(l)+fac(r));
   }
   
   cout<<ans+1<<endl;
   //system("pause");
   return 0;
}
