#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   ll n,k;
   cin>>n>>k;
   cout<<min(n%k,k-n%k)<<endl;
   //system("pause");
   return 0;
}
