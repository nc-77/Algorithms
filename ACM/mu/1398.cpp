#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e3+10;
vector<int>g;
int dp[maxn];
int main()
{
   //ios::sync_with_stdio(false);
   for(int i=1;i<=17;i++) g.push_back(i*i);
   dp[0]=1;
   for(int i=0;i<17;i++)
    for(int j=1;j<=300;j++)
    {
        if(j>=g[i])
        {
            dp[j]+=dp[j-g[i]];
        }
        
    }
    int n;
    while(cin>>n&&n) cout<<dp[n]<<endl;
   //system("pause");
   return 0;
}
