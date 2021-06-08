#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;
int x[maxn],y[maxn],f[maxn];
vector<int>xx,yy,gg,mm;
int main()
{
   int n;
   cin>>n;
   for(int i=1;i<=n;i++) x[i]=1;
   for(int i=1;i<=n;i++)
   {
       cin>>f[i];
       if(f[i]==0) xx.push_back(i),x[i]=0;
       y[f[i]]=1;
   }
    for(int i=1;i<=n;i++) 
    {
        if(!y[i]&&x[i]) yy.push_back(i);
        else if(!x[i]&&!y[i]) mm.push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(!x[i]&&!y[i])  gg.push_back(i);
    }
    int flag=1,len=xx.size();
   
   int cnt=0;
   
    int st=1;
   
    len=mm.size();
    if(gg.size()==1) f[gg[0]]=yy[0],yy.erase(yy.begin()),yy.push_back(gg[0]);
    else if(gg.size()>1)
    {
         f[gg[0]]=mm[len-1];
    for(int i=1;i<gg.size();i++)
     f[gg[i]]=mm[cnt++];
    }

     cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(f[i]==0)
        {
            f[i]=yy[cnt++];
        }
        cout<<f[i]<<" ";
    }
   //system("pause");
   return 0;
}
