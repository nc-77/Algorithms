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
   int n,m;
   while(cin>>n>>m)
   {
       if(!n&&!m) break;
       if(n%2==0||n%2==1&&m%2==0) cout<<"Wonderful!"<<endl;
       else cout<<"What a pity!"<<endl;
   }
   //system("pause");
   return 0;
}
