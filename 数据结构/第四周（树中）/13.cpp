#include<iostream>
#include<set>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
const int maxn=1e5;
int par[maxn];
int find(int x)
{
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}
void  unite(int x,int y)
{
     x=find(x);
     y=find(y);
     if(x==y) return;
     par[x]=y;
}

int main()
{
    int n,x,y;
    char ch;
    cin>>n;
    for(int i=0;i<=n;i++) par[i]=i;
    getchar();
    while(cin>>ch)
    {
        if(ch=='S') break;
        
        else if(ch=='I') 
        {
            cin>>x>>y;
            unite(x,y);
        }
        else if(ch=='C'){
            cin>>x>>y;
            if(find(x)==find(y)) puts("yes");
            else puts("no");
        }
     }
     set<int>s;
     for(int i=1;i<=n;i++)
     {
         s.insert(find(i));
     }
     if(s.size()==1) puts("The network is connected.");
     else printf("There are %d components.",s.size());
   return 0;
}
