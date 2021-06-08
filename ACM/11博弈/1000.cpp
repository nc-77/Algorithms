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
   int t;
   cin>>t;
   while(t--)
   {
       int n,m;
       cin>>n>>m;
       if(n%(m+1)) cout<<"first"<<endl;
       else cout<<"second"<<endl;
   }
   //system("pause");
   return 0;
}
