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
   int n;
   cin>>n;
   string s;
   for(int i=1;i<=n;i++) cin>>s;
   int m;
   cin>>m;
   for(int i=1;i<=m;i++) cin>>s;
   
   if(n>m) cout<<"Cuber QQ"<<endl;
   else cout<<"Quber CC"<<endl;
   //system("pause");
   return 0;
}
