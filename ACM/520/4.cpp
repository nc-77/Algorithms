#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   //ios::sync_with_stdio(false);
   ll a,b;
   cin>>a>>b;
   ll x=a+b;
   string ans=to_string(x);
   for(int i=0;i<ans.size();i++)
   if(i!=ans.size()-1)cout<<ans[i]<<endl;
   //system("pause");
   return 0;
}
