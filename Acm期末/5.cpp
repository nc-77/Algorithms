#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int n,m,x,y;
char a[105][105];
int vis[105][105];
struct pos
{
    int x,y;
}cur,nex;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int bfs(){
    memset(vis,0,sizeof(vis));
    vis[x][y]=1;
    int ans=0;
    queue<pos>que;
    que.push({x,y});
    while(!que.empty()){
        cur=que.front();
        que.pop();
        ans++;
        for(int i=0;i<4;i++){
            nex.x=cur.x+dx[i];
            nex.y=cur.y+dy[i];
            if(nex.x<1||nex.x>n||nex.y<1||nex.y>n) continue;
            if(!(a[cur.x][cur.y]=='W'&&a[nex.x][nex.y]=='A'||a[cur.x][cur.y]=='A'&&a[nex.x][nex.y]=='W')) continue;
            if(!vis[nex.x][nex.y])
            que.push(nex);
            vis[nex.x][nex.y]=1;
        }
    }
    return ans;
}
int main()
{
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<m;i++){
            cin>>x>>y;
            cout<<bfs()<<endl;
        }
    }
   return 0;
}
