#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll ans[maxn];
int main()
{
   int n,x,y;
   cin>>n>>x>>y;
   for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    {
        int t1=j-i;
        int t2=1+abs(y-j)+abs(x-i);
        int t3=1+abs(x-j)+abs(y-i);
        int t=min(t1,min(t2,t3));
        ans[t]++;
        //if(t==2) debug(i),debug(j);
    }
    for(int i=1;i<n;i++)
    cout<<ans[i]<<endl;
   //system("pause");
   return 0;
}
