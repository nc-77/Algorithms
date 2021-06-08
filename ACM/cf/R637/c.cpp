#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],b[maxn];
map<int,int>mp;
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       mp.clear();
       for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]=i;
       for(int i=1;i<=n;i++)
       {
           b[i]=mp[i];
           //debug(b[i]);
       }
       int flag=1;
       int now=n;
       int mi=b[1];
        for(int i=2;i<=n;i++)
        {
            if(b[i]-b[i-1]==1) 
            {
                mi=min(b[i],mi);
                continue;
            }
            else
            {
                if(b[i-1]!=now) {
                    flag=0;
                    break;
                }
                now=mi-1;
                mi=b[i];
            }
        }
        if(flag)  puts("Yes");
       else puts("No");
   }
   //system("pause");
   return 0;
}
