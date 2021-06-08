#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;
int main()
{
    int n,m;
    cin>>n>>m;
    string s1,s2;
    cin>>s1>>s2;
    int minn=min(n,m);
    int ans=fabs(n-m);
    for(int i=0;i<minn;i++)
    {
        if(s1[i]!=s2[i]) ans++;
    }
    cout<<ans<<endl;
}
