#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;
int mod(int x,int y)
{
   return (x%y+y)%y;
}
int a[maxn],b[maxn];
signed main()
{
   ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
      int n;
      cin>>n;
   
      for(int i=0;i<n;i++) cin>>a[i];
      for(int i=0;i<n;i++)
      {
         b[i]=mod(i+a[mod(i,n)],n);
      }
      int flag=1;
      sort(b,b+n);
      for(int i=1;i<n;i++)
      {
         if(b[i]-b[i-1]!=1)  flag=0;
      }
      if(!flag) cout<<"NO"<<endl;
      else cout<<"YES"<<endl;
   }
   //system("pause");
   return 0;
}
