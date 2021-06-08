#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e3+10;
char a[maxn][maxn];
int par[maxn*maxn];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int find(int x){
    if(x==par[x]) return x;
    return par[x]=find(par[x]);
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    par[x]=y;
}
int main()
{
   //ios::sync_with_stdio(false);
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
   for(int i=1;i<=n;i++)
   {
       int flag=0;
       for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='#'&&!flag){flag=1;continue;}
            if(flag&&a[i][j]=='#'&&a[i][j-1]=='.') {
                //debug(i),debug(j);
                cout<<-1;
                return 0;
            }
        }
   }
   for(int i=1;i<=m;i++)
   {
       int flag=0;
       for(int j=1;j<=n;j++)
        {
            if(a[j][i]=='#'&&!flag){flag=1;continue;}
            if(flag&&a[j][i]=='#'&&a[j-1][i]=='.') {
                cout<<-1;
                return 0;
            }
        }
   }
   int h=0,l=0;
   for(int i=1;i<=n;i++)
   {
       int cnt=0;
       for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='.') cnt++;
        }
        if(cnt==m) h=1;
   }
   for(int i=1;i<=m;i++)
   {
       int cnt=0;
       for(int j=1;j<=n;j++)
        {
            if(a[j][i]=='.') cnt++;
        }
        if(cnt==n) l=1;
   }    
    if(h+l==1) {cout<<-1<<endl;return 0;}
    for(int i=1;i<=n*m;i++) par[i]=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='#')
            for(int k=0;k<4;k++)
            {
                int x=i+dx[k],y=j+dy[k];
                if(x<1||x>n||y<1||y>m||a[x][y]=='.') continue;
                unite((i-1)*m+j,(x-1)*m+y);
                //debug(i),debug(j),debug(x),debug(y);
            }
        }
    int ans=0;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++){
            if(a[i][j]=='#'&&par[(i-1)*m+j]==(i-1)*m+j) {ans++;}
        }
    cout<<ans<<endl;
   //system("pause");
   return 0;
}
