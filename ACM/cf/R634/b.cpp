#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
map<int,int>mp;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,a,b;
       cin>>n>>a>>b;
        mp.clear();
        string s;
        int cnt=0;
        for(int i=1;i<=b;i++) 
        {
            s+=char('a'+cnt);
            cnt++;
        }
        for(int i=1;i<=a-b;i++)
        s+='a';
        //debug(s);
        string ans;
        while(1)
        {
            for(int i=1;i<=a;i++)
        {
            ans+=s[i-1];
            if(ans.size()==n) break;
        }
        if(ans.size()==n) break;
        }
        cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
