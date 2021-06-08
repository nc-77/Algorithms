#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;
int a[maxn],cnt[maxn][210];
vector<int>g[250];
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       for(int i=1;i<=200;i++) g[i].clear();
       for(int i=1;i<=n;i++) for(int j=1;j<=200;j++)cnt[i][j]=0;
       for(int i=1;i<=n;i++) 
       {
           cin>>a[i];
            g[a[i]].push_back(i);
            for(int j=1;j<=200;j++)
            cnt[i][j]=cnt[i-1][j];
            cnt[i][a[i]]++;
       }
      
       int ans=1,sum=0;
        for(int i=1;i<=200;i++)
        {
            int len=g[i].size();
            for(int j=1;j<=len/2;j++)
            {
                
                for(int k=1;k<=200;k++)
                {
                    sum=j*2;
                    sum+=cnt[g[i][len-j]-1][k]-cnt[g[i][j-1]][k];
                  ans=max(ans,sum);
                   
                }
                
            }
        }
        cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
