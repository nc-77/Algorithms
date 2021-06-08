#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int vis[35][35][35];
int dfs(int a,int b,int c){
    if(vis[a][b][c]) return vis[a][b][c];
    if(a<=0||b<=0||c<=0)
        return 1;
    else if(a>20||b>20||c>20) return vis[a][b][c]=dfs(20,20,20);
    else if(a<b&&b<c)
        return vis[a][b][c]=dfs(a,b,c-1)+dfs(a,b-1,c-1)-dfs(a,b-1,c);
    else 
        return vis[a][b][c]=dfs(a-1,b,c)+dfs(a-1,b-1,c)+dfs(a-1,b,c-1)-dfs(a-1,b-1,c-1);
}
int main()
{
   int a,b,c;
   while(cin>>a>>b>>c){
       
       cout<<dfs(a,b,c)<<endl;
   }
   return 0;
}
