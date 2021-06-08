#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define PII pair<int,int>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int p[maxn],ans[maxn],par[maxn];
int find(int x)
{
	if(par[x]==x) return x;
	else return par[x]=find(par[x]);
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(x<y)par[y]=x;
    else par[x]=y;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
     
       for(int i=1;i<=n;i++) cin>>p[i],ans[i]=0,par[i]=i;
       for(int i=1;i<=n;i++)
       {
           unite(i,p[i]);
           
       }
       for(int i=1;i<=n;i++) ans[find(i)]++;
       for(int i=1;i<=n;i++)
        {
            cout<<ans[find(i)]<<" ";
        }
       cout<<endl;
   }
   //system("pause");
   return 0;
}
