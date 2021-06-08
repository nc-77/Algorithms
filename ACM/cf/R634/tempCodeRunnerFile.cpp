#include<bits/stdc++.h>

#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int vis[2050][30],r[30],l[30],rr[30],ll[30];
int a[maxn];
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
        set0(vis);
        set0(r),set0(l);
        set0(ll);
        int ans=1;
        for(int i=1;i<=n;i++) cin>>a[i],r[a[i]]++,ans=max(ans,r[a[i]]);
      
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=26;j++)
            {
                vis[i][j]=vis[i-1][j];
            }
            vis[i][a[i]]++;
        }
            
        for(int i=1;i<=n;i++)
        {
            r[a[i]]--;
            for(int j=1;j<=26;j++)
            {
                int x=0,rt=0;
                if(l[j]==0||r[j]==0) continue;
                x+=min(l[j],r[j])*2;
                for(int k=i+1;k<=n;k++)
                {
                    if(a[k]==j) {
                        rt=k;
                        break;
                    }
                }
                x+=vis[rt-1][a[i]]-vis[ll[j]][a[i]];
                ans=max(ans,x);
                // debug(ans);
                // debug(j);
                // debug(i);
            }
            l[a[i]]++;
            ll[a[i]]=i;
        }
        cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
