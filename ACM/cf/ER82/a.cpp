#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int f=0,last=0,ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1') f=1;
            if(f&&s[i]=='0') ans++;
            if(s[i]=='1') last=i;
        }
        for(int i=last;i<s.size();i++)
        {
            if(s[i]=='0') ans--;
        }
        cout<<max(ans,0)<<endl;
    }
}
