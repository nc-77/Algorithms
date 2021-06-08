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
       int n;
       cin>>n;
       getchar();
        int flag=1;
    for(int i=1;i<=n+1;i++) for(int j=1;j<=n+1;j++) a[i][j]=1;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%1d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            
            if(a[i][j]==1&&a[i+1][j]==0&&a[i][j+1]==0) 
            flag=0;
        }
        if(flag) cout<<"yes";
        else cout<<"no";
        cout<<endl;
   }
   
   //system("pause");
   return 0;
}
