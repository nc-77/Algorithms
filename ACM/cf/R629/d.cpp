#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],ans[maxn];
set<ll>s;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
      int n;
      cin>>n;
      s.clear();
      for(int i=1;i<=n;i++) cin>>a[i],s.insert(a[i]);
      int flag=0;
      if(s.size()==1)
      {  cout<<1<<endl;
          for(int i=1;i<=n;i++)
          cout<<1<<" ";
          cout<<endl;
          continue;
      }
      int last=0;
      for(int i=1;i<n;i++)
      {
         if(a[i]==a[i+1]) flag=1,last=i+1;
      }
      if(flag)
      {
      		int f=0;
         cout<<2<<endl;
         ans[1]=1;
         int temp=n-last;
         if(temp%2)ans[last]=1;
         else ans[last]=2;
         for(int i=last+1;i<=n;i++) ans[i]=3-ans[i-1];
         for(int i=2;i<last;i++)
         {
         	if(a[i]!=a[i-1]) ans[i]=3-ans[i-1];
         	else ans[i]=ans[i-1];
		 }
        for(int i=1;i<=n;i++)
         cout<<ans[i]<<" ";
         cout<<endl;
      }
      else{
         ans[1]=1;
         for(int i=2;i<=n;i++)
         {
            ans[i]=3-ans[i-1];
         }
         if(a[1]!=a[n]&&ans[1]==ans[n])
         {
            cout<<3<<endl;
            ans[n]=3;
         }
         else cout<<2<<endl;
         for(int i=1;i<=n;i++)
         cout<<ans[i]<<" ";
         cout<<endl;
      }
   }
   //system("pause");
   return 0;
}
