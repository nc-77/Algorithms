#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int nex[maxn];
int main()
{
   string s;
   while(cin>>s)
   {
       s=" "+s;
       int cur=0,last=0;
        set0(nex);
        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='[') cur=0;
            else if(s[i]==']') cur=last;
            else{
                nex[i]=nex[cur];
                nex[cur]=i;
                if(cur==last) last=i;
                cur=i;

            }
        }
        for(int i=0;nex[i]!=0;i=nex[i])
        cout<<s[nex[i]];
        cout<<endl;
   }
   //system("pause");
   return 0;
}
