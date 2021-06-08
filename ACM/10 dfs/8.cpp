#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int ans[maxn];
int a[maxn],n,vis[maxn];
void dfs(int x,int k)
{
    if(x>n+1) return;
    if(k==6) 
    {
        cout<<ans[0];
        for(int i=1;i<6;i++) cout<<" "<<ans[i];
        cout<<endl;
        return;
    }
    ans[k]=a[x];
    dfs(x+1,k+1);
    dfs(x+1,k);
}
int main()
{
   ios::sync_with_stdio(false);
   int t=0;
   while(cin>>n&&n)
   {
       if(t++) cout<<endl;
       for(int i=1;i<=n;i++) cin>>a[i];
       sort(a+1,a+n+1);
       dfs(1,0);
       
   }
   //system("pause");
   return 0;
}

