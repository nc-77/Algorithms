#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   string s1,s2;
   cin>>s1>>s2;
   int n1=s1.size();
   int n2=s2.size();
   if(s1==s2) puts("-1");
   else cout<<max(n1,n2)<<endl;
   //system("pause");
   return 0;
}
