#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int ha[maxn],f[maxn];
vector<int>g;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{   int n;cin>>n;
    int st=0;
   for(int i=1;i<=n;i++) 
   {
       cin>>f[i],ha[f[i]]=1;
       if(f[i]==0&&st==0) st=i;
   }
   for(int i=1;i<=n;i++) if(!ha[i])  g.push_back(i);
   for(int i=0;i<g.size();i++)
   {
       if(st!=g[i]) 
       {
           f[st]=g[i];
           g.erase(g.begin()+i);
           break;
       }
   }
   int flag=0,num=0;
   
       for(int i=st+1;i<=n;i++)
       {
           if(f[i]==0) f[i]=g[num++];
           if(f[i]==i) swap(f[st],f[i]);
       }
   
   for(int i=1;i<=n;i++)
   cout<<f[i]<<" ";
   //system("pause");
   return 0;
}
