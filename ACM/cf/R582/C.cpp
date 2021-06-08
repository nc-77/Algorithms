#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[100][100];
signed main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   for(int i=1;i<=10;i+=2)
        for(int j=1;j<=10;j++)
   {
       a[i][j]=(a[i][j-1]+i)%10;
   }
   for(int i=2;i<=8;i+=2)
        for(int j=1;j<=5;j++)
   {
       a[i][j]=(a[i][j-1]+i)%10;
   }
   while(t--)
   {
       int n,m;
       cin>>n>>m;
        int k=n/m;
        int x=m%10;
        int ans=0;
        if(x==0){
            ans=0;
        }
        else if(x==5){
            ans+=k/2*5;
            for(int i=1;i<=k%2;i++)
            ans+=a[5][i];
        }
        else if(x%2==1){
            ans+=k/10*45;
            for(int i=1;i<=k%10;i++)
            ans+=a[x][i];
        }
        else if(x%2==0){
            ans+=k/5*20;
            for(int i=1;i<=k%5;i++)
            ans+=a[x][i];
        }
        cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
