#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
struct node
{
    int x,y,ch;
};
vector<node>g1,g2;
bool work(int a,int b,int c)
{
    int p=0,q=0,P=0,Q=0;
    for(int i=0;i<g1.size();i++)
    {
        if(a+g1[i].x*b+g1[i].y*c<0) p++;
        else q++;
    }
    for(int i=0;i<g2.size();i++)
    {
        if(a+g2[i].x*b+g2[i].y*c<0) P++;
        else Q++;
    }
    if(!p&&!Q||!q&&!P) return true;
    return false;
}
int main()
{
   int n,m;
   cin>>n>>m;
   for(int i=0;i<n;i++)
   {
       int x,y;
        char ch;
       cin>>x>>y>>ch;
       if(ch=='A')g1.push_back({x,y});
      else g2.push_back({x,y});
   }
   while(m--)
   {
       int a,b,c;
       cin>>a>>b>>c;
       if(work(a,b,c)) puts("Yes");
       else puts("No");
   }
   return 0;
}
