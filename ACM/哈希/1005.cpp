#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
map<string,int>mp;
int main()
{
   //ios::sync_with_stdio(false);
   string s;
   while(getline(cin,s))
   {    mp.clear();
       if(s=="#") break;
        istringstream is(s);
        int ans=0;
        string t;
        while(is>>t)
        {
            if(!mp[t]) ans++;
            mp[t]=1;
        }
        cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
