#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e2+10;
char a[maxn][maxn];
int tag[maxn][maxn];
int flag;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
struct pos
{
    int x, y;
};
int n,m,k;
bool check(int x,int y){
    if(x<1||x>n||y<1||y>m||a[x][y]=='R'||a[x][y]=='X') return false;
    return true;
}
vector<pos>g;
void dfs(int step){
    if(flag) return;
    if(step>k) return;
    for(int i=0;i<g.size();i++){
        int sx=g[i].x,sy=g[i].y;
        if(a[sx][sy]=='D'&&step==k) {
                flag=1;
                return;
            }
        for(int j=0;j<4;j++){
            int nx=g[i].x,ny=g[i].y;
            while(check(nx+dx[j],ny+dy[j]))
             nx+=dx[j],ny+=dy[j];
             //debug(nx),debug(ny);
             if(tag[nx][ny]&&step+1==k) {
                 flag=1;
                 return;
             }
             if(nx==sx&&ny==sy) dfs(step+1);
            else {
                a[sx][sy]='.';
                a[nx][ny]='R';
                g[i].x=nx;g[i].y=ny;
                dfs(step+1);
                a[sx][sy]='R';  
                a[nx][ny]='.';
                g[i].x=sx;g[i].y=sy;
            }
            
        }
    }
}
int main()
{
   //ios::sync_with_stdio(false);
   
   cin>>m>>n>>k;
   for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
       cin>>a[i][j];
       if(a[i][j]=='R') g.push_back({i,j});
       if(a[i][j]=='D') tag[i][j]=1;
    }
   dfs(0);
   if(flag) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
   //system("pause");
   return 0;
}
