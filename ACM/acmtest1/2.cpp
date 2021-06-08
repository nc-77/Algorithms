#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       string s;
       cin>>s;
       for(int i=0;i<s.size();i++)
       if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
       cout<<s<<endl;
   }
   //system("pause");
   return 0;
}
