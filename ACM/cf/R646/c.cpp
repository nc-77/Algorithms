#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
vector<int>g[maxn];

int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n,x;
       cin>>n>>x;
       int ans=0;
       for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            
        }
       ans=n-2;
        if(g[x].size()==1||n==1) cout<<"Ayush"<<endl;
        else {
            if(ans%2)  cout<<"Ashish"<<endl;
            else cout<<"Ayush"<<endl;
        }
   }
   //system("pause");
   return 0;
}
