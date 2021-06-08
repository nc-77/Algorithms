#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
const int maxn=1e6+10;
struct Node
{
    int pos,nex,data;
}node[maxn];

int main()
{
   int head,n,k;
   cin>>head>>n>>k;
   for(int i=0;i<n;i++)
   {
       int pos,nex,x;
       cin>>pos>>x>>nex;
       node[pos].data=x;
       node[pos].pos=pos;
       node[pos].nex=nex;
   }
   vector<int>g;
   while(head!=-1)
   {
       g.push_back(head);
       head=node[head].nex;
   }
   int st=0;
   while(st+k<=g.size())
   {
         reverse(g.begin()+st,g.begin()+st+k);
         st=st+k;
   }
   g.push_back(-1);
   for(int i=0;i<g.size()-1;i++)
   {    if(g[i+1]==-1)
       printf("%05d %d -1",g[i],node[g[i]].data);
       else 
       printf("%05d %d %05d\n",g[i],node[g[i]].data,g[i+1]);
   }
   //system("pause");
   return 0;
}
