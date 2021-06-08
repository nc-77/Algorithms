#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
char a[100][100];
bool check(int x,int y)
{
    if(a[x][y]=="B") {
        if(a[x+1][y]=="G"||a[x][y+1]=="G"||a[x-1][y]=="G"||a[x][y-1]=="G") return false;

    }
    if(a[x][y]=="G") {
        if(a[x+1][y]=="B"||a[x][y+1]=="B"||a[x-1][y]=="B"||a[x][y-1]=="B") return false;

    }
    return true;
}
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n,m;
       cin>>n>>m;
       set0(a);
       for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
       int flag=1;
       for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(!check(i,j)) flag=0;
        }
        if(a[n-1][m]=="#"&&a[n][m-1]=="#") flag=0;
        if(flag) puts("yes");
        else cout<<"no"<<endl;
   }
   //system("pause");
   return 0;
}
