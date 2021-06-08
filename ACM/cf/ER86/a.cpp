#include<bits/stdc++.h>
#define ll long long

using namespace std;
#define int long long

signed main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int a,b,x,y,ans;
       cin>>x>>y>>a>>b;
       if(a*2<=b)
       {
            ans=a*(x+y);
       }
       else 
       {
           ans=b*min(x,y)+a*abs(x-y);

       }
        cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
