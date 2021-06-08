#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int par[maxn],l[maxn];
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
{
   int x,y;
   int cnt=1;
   while(1)
   {    init(200000);
   		set0(l);
        int flag=1,f=1;
        set<int>s;
       while(cin>>x>>y)
       {
           if(x==y&&x==0) break;
           if(x<0) {f=0;break;}
           if(same(x,y)) flag=0;
            unite(x,y);
           s.insert(x),s.insert(y);
           l[y]++;
       }
       if(!f) break;
       int ans=0;
      for(auto x:s)
      {
          if(x==par[x]) ans++;
          if(l[x]>1) flag=0;
      }
      if(ans>1) flag=0; 
       if(flag) 
       printf("Case %d is a tree.\n",cnt++);
       else
       printf("Case %d is not a tree.\n",cnt++);
   }
   //system("pause");
   return 0;
}
