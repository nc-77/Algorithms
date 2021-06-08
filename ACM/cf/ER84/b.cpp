#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;
vector<int> g[maxn];
int vis[maxn],f[maxn],d[maxn];
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       for(int i=1;i<=n;i++) vis[i]=f[i]=d[i]=0;
       for(int i=1;i<=n;i++) 
       {
           int k,x;
           cin>>k;
           g[i].clear();
           for(int j=1;j<=k;j++)
           cin>>x,g[i].push_back(x),vis[x]++;
       }
       for(int i=1;i<=n;i++)
       sort(g[i].begin(),g[i].end());
        for(int i=1;i<=n;i++)
        {   int mx=0;
            for(int j=0;j<g[i].size();j++)
            {   if(!f[g[i][j]]) 
                {
                    mx=g[i][j];
                    break;
                }
            }
            if(mx) f[mx]=d[i]=1;
            //debug(mx);
        }
        int ansk=0,ansd=0;
        for(int i=1;i<=n;i++) 
        {
            if(!f[i]) ansk=i;
            if(!d[i]) ansd=i;
        }
        if(!ansk||!ansd) 
        {
            cout<<"OPTIMAL"<<endl;
            continue;
        }
        cout<<"IMPROVE"<<endl;
        cout<<ansd<<" "<<ansk<<endl;
   }
   //system("pause");
   return 0;
}
