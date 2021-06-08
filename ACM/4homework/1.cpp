#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e3+10;
ll a[maxn][maxn];
int main()
{
   
        int cnt=1;
        ll n;
        for(int i=1;i<=35;i++) a[i][0]=1;
        for(int  i=1;i<=35;i++)
        {
             for(int j=1;j<=i;j++)
             {
                  if(j==i) a[i][j]=a[i][j-1];
                  else a[i][j]=a[i-1][j]+a[i][j-1];
             }
        }
   while(cin>>n&&n!=-1)
   {      
            cout<<cnt++<<" "<<n<<" ";
               cout<<a[n][n]*2<<endl;

        
   }
   //system("pause");
   return 0;
}
