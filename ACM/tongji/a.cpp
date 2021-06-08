#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int gcd(int a,int b){
   return b==0?a:gcd(b,a%b);
}
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
      int n,a,b;
      cin>>n>>a>>b;
      int k=gcd(a,b);
      int cnt=n/k;
      if(cnt%2) cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
   }
   //system("pause");
   return 0;
}
