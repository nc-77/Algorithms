#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
vector<int>g;
int ans[maxn];
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int m=n,x=1;
       g.clear();
        while(1)
        {
            if(m-x>=0)
            {
                g.push_back(x);
                 m-=x;
                x=x<<1;
               
            }
           else break;
        }
        
        if(m>0) g.push_back(m);
        sort(g.begin(),g.end());
        for(int i=1;i<g.size();i++)
        ans[i]=g[i]-g[i-1];
        cout<<g.size()-1<<endl;
        for(int i=1;i<g.size();i++)
        cout<<ans[i]<<" ";
        cout<<endl;
   }
   //system("pause");
   return 0;
}
