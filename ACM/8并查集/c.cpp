#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e7+10;
int par[maxn];
map<int,int>mx;
void init(int n){
	for(int i=1;i<=n;i++) par[i]=i;
} 
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
	par[y]=x;
}
bool same(int x,int y){
	return find(x)==find(y);	
}
int main()
{ios::sync_with_stdio(false);
   int n;
   while(cin>>n)
   {
       init(maxn);mx.clear();
       set<int>s;
       for(int i=1;i<=n;i++) 
       {
           int x,y;
           cin>>x>>y;
           unite(x,y);
           s.insert(x),s.insert(y);
       }
       int ans=1;
        for(auto x:s)
        {
            mx[find(x)]++;
            ans=max(ans,mx[find(x)]);
        }
        cout<<ans<<endl;
   }
   
   //system("pause");
   return 0;
}
