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
        string a,b,c;
        cin>>a>>b>>c;
        int flag=1;
        for(int i=0;i<a.size();i++)
        {
            if(c[i]!=a[i]&&c[i]!=b[i])
            {
                flag=0;
                break;
            }
        }
        if(flag) puts("YES");
        else puts("NO");
    }
}
