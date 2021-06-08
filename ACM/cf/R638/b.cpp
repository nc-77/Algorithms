#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e3+10;
int a[maxn],ans[maxn];
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n,k;
        cin>>n>>k;
        set<int>s;
        for(int i=1;i<=n;i++) cin>>a[i],s.insert(a[i]);
        if(s.size()>k) {
            puts("-1");
            continue;
        }
        int cnt=0;
        while(1)
        {
            for(auto x:s)
            {
                ans[cnt++]=x;
                if(cnt==k) break;
            }
            if(cnt==k) break;
        }
        
        
        cout<<n*k<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<k;j++)
            cout<<ans[j]<<" ";

        }
        
        cout<<endl;

   }
   //system("pause");
   return 0;
}
