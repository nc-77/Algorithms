#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
#define int long long
int a[15],k,flag;
void dfs(int x,int cnt,int sum,string ans)
{
    if(flag) return;
    if(x<-1||cnt>k) return;
    if(cnt==k&&sum%3==0)
    {
        flag=1;
        cout<<ans<<endl;
        return;
    }
    int mx=min(a[x],k-cnt);
    
    for(int i=mx;i>=max(mx-2,0ll);i--)
    {
        if(cnt==0&&x==0&&i>1) continue;
        string s(i,x+'0');
        dfs(x-1,cnt+i,sum+i*x,ans+s);

    }
}
signed main()
{
   int t;
   cin>>t;
   while(t--)
   {
       string s,ans;
       
       cin>>s>>k;
        set0(a);
        for(int i=0;i<s.size();i++)
        a[s[i]-'0']++;
        flag=0;
        dfs(9,0,0,ans);
        if(!flag) puts("-1");
   }
   //system("pause");
   return 0;
}
