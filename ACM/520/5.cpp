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
   string s;
   cin>>s;
   int n=s.size();
   string t;
   while(cin>>t)
   {
       if(t=="-1") break;
    if(n!=t.size()) {cout<<"No"<<endl;}
    else {
        int cnt=0;
        for(int i=0;i<n;i++)
        if(s[i]!=t[i]&&abs(s[i]-t[i])>1) cnt++;
        //debug(cnt);
        if(cnt>=1) cout<<"No"<<endl;
        else puts("Yes");
    }
   }
   //system("pause");
   return 0;
}
