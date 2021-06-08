#include<iostream>
#include<cmath>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int n,flag;
double d;
const double  ISLAND=15.0/2;
int vis[105];
struct node
{
    double x,y;
}p[105];

bool fjump(int i){
	return sqrt( p[i].x*p[i].x+p[i].y*p[i].y )<=d+ISLAND;
}
bool jump(int x,int y){
	return sqrt( (p[x].x-p[y].x)*(p[x].x-p[y].x)+(p[x].y-p[y].y)* ( p[x].y-p[y].y) )<=d;
}
bool judge(int i){
	return (abs(p[i].x)>=50-d||abs(p[i].y)>=50-d);
}

void dfs(int x)
{
    vis[x]=1;
    if(judge(x)||flag){
        flag=1;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i]&&jump(x,i))
        dfs(i);
    }
}
int main()
{
   cin>>n>>d;
   for(int i=0;i<n;i++)
   {
       cin>>p[i].x>>p[i].y;
   }
    for(int i=0;i<n;i++)
    {
        if(!vis[i]&&fjump(i)){
            dfs(i);
        }
    }
    if(flag||d>=50) puts("Yes");
    else puts("No");
   return 0;
}
