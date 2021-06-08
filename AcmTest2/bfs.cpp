#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
const int maxn=1010;
int n,m;
int vis[maxn][maxn];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int startx,starty,endx,endy;
char a[maxn][maxn];
struct pos
{
    int x,y;
    int step;
}cur,nex;
bool judge(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m) return true;
    return false;
}
int bfs(){
    memset(vis,sizeof(vis),0);
    queue<pos>que;
    que.push({startx,starty,0});
    vis[startx][starty]=1;
    while (!que.empty())
    {
        cur=que.front();
        que.pop();
        if(cur.x==endx&&cur.y==endy)
            return cur.step;
        for(int i=0;i<4;i++){
            nex.x=cur.x+dx[i];
            nex.y=cur.y+dy[i];
            nex.step=cur.step+1;
            if(!judge(nex.x,nex.y)) continue;
            if(a[nex.x][nex.y]==''&&!vis[nex.x][nex.y]){
                que.push(nex);
                vis[nex.x][nex.y]=1;
            }
            else if(a[nex.x][nex.y]==''){
                nex.x=dx[i];
                nex.y=dy[i];
                if(judge(nex.x,nex.y)&&a[nex.x][nex.y]==''&&!vis[nex.x][nex.y]){
                    que.push(nex);
                    vis[nex.x][nex.y]=1;
                }
            }
        }
    }
    return -1;
}
int main()
{
   while(cin>>n>>m){
       for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
        cout<<bfs()<<endl;
   }
   return 0;
}

