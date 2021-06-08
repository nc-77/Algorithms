#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
map<int,int>mp;
signed main()
{
  // ios::sync_with_stdio(false);
   int a,b,c,d;
   while(cin>>a>>b>>c>>d)
   {
       if ((a > 0 && b > 0 && c > 0 && d > 0) || (a < 0 && b < 0 && c < 0 && d < 0)) {
            printf("0\n");
            continue;
        }
       mp.clear();
       for(int i=-100;i<=100;i++)
        for(int j=-100;j<=100;j++)
        {
            if(i==0||j==0) continue; 
            mp[i*i*a+j*j*b]++;
        }
        
        int ans=0;
         for(int i=-100;i<=100;i++)
        for(int j=-100;j<=100;j++)
        {
             if(i==0||j==0) continue; 
            int x=i*i*c+j*j*d;
            ans+=mp[-x];
        }
        cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
