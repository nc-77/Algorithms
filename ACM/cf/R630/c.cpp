#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;
#define int long long
int bit[maxn][30];
int cnt[maxn];
signed main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,k;
       cin>>n>>k;
        string s;
        cin>>s;
        s=" "+s;
        for(int i=1;i<=n;i++) for(int j=0;j<26;j++) bit[i][j]=cnt[i]=0;
        for(int i=1;i<=n;i++)
        {
           int x=i%k;
           if(x==0) x=k;
           if(x>=k/2+1) x=k+1-x;
           bit[x][s[i]-'a']++;
           cnt[x]++;
           //debug(x),debug(s[i]-'a');
        }
        int ans=0;
        for(int i=1;i<=(k/2+1);i++)
        {   int mx=0;
            for(int j=0;j<26;j++)
            {
                mx=max(mx,bit[i][j]);
            }
            ans+=cnt[i]-mx;
        }
        cout<<ans<<endl;
   }
   

   //system("pause");
   return 0;
}
