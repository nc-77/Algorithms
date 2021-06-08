#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[105];
signed main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int x;
       cin>>x;
       int n=x;
       for(int i=0;i<=100;i++) a[i]=0;
       int cnt=0;
        while(x)
        {
            a[cnt++]=x%3;
            x=x/3;
        }
        //  for(int i=cnt;i>=0;i--) debug(a[i]);
        //  cout<<"h"<<endl;
        int ans=0,last=-1;
        for(int i=0;i<cnt;i++)
        {
            if(a[i]==2)
            {
                a[i]=0;
                last=i;
            }
        }
        if(last!=-1)
        {
            int now=0;
            for(int i=last+1;i<=cnt;i++) 
            {
                if(a[i]==0) {
                a[i]=1;
                now=i;
                break;
                } 
            }
            // for(int i=cnt;i>=0;i--) debug(a[i]);
             for(int i=0;i<now;i++) a[i]=0; 
            int k=1;
            for(int i=0;i<=cnt;i++)  
            {
                ans+=a[i]*k;
                k=k*3;
            }
            cout<<ans<<endl;
        }
        else cout<<n<<endl;
   }
   //system("pause");
   return 0;
}
