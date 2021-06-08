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
   int n,k;
   cin>>n>>k;
   for(int i=1;i<=n;i++)
   {
       if(i==k) cout<<"a";
       else if(i>k) cout<<"c";
       else cout<<"b";
    
   }
   
   //system("pause");
   return 0;
}
