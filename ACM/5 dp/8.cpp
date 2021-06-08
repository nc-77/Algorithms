#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll a[maxn];
int main()
{   int cnt=1;
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       ll st=1,ed=1,sum=0;
      
      int x=1,y=1;
       for(int i=1;i<=n;i++) cin>>a[i];
       ll ans=a[1];
       for(int i=1;i<=n;i++)
       {    
           sum+=a[i];
           if(sum>ans) x=st,ed=i,ans=sum;
           if(sum<0) sum=0,st=i+1;
            
       }
        printf("Case %d:\n",cnt++);
        cout<<ans<<" "<<x<<" "<<ed<<endl;
   if(t) cout<<endl;
   }
   //system("pause");
   return 0;
}

