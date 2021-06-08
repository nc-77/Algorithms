#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],b[maxn];
int main()
{
   ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n,k;
       cin>>n>>k;
       for(int i=1;i<=n;i++) cin>>a[i],b[i]=0;
       for(int i=2;i<n;i++)
       {
           if(a[i]>a[i-1]&&a[i]>a[i+1]) b[i]=1;
       }
       int cnt=0;
       for(int i=2;i<k;i++)
       {
           if(b[i]) cnt++;
       }
       int ans=cnt,ap=1;
       for(int i=2;i<=n&&i+k-1<=n;i++)
       {
           if(b[i]) cnt--;
           if(b[i+k-2]) cnt++;
           if(cnt>ans)
           {
               ans=cnt;
               ap=i;
           }
       }
       cout<<ans+1<<" "<<ap<<endl;
   }
   //system("pause");
   return 0;
}
