#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[100][100];
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n,m;
       cin>>n>>m;
       for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
       int x=0,y=0;
       for(int i=1;i<=n;i++)
       {
           int flag=1;
           for(int j=1;j<=m;j++)
        {
            if(a[i][j]) flag=0;
        }
        if(flag) x++;
       }
       for(int i=1;i<=m;i++)
       {
           int flag=1;
           for(int j=1;j<=n;j++)
        {
            if(a[j][i]) flag=0;
        }
        if(flag) y++;
       }
        x=min(x,y);
        if(x%2) cout<<"Ashish"<<endl;
        else cout<<"Vivek"<<endl;
   }
   //system("pause");
   return 0;
}
