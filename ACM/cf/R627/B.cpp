#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e4+10;
map<int,int>mp;
int main()
{
   int t;
   cin>>t;
    while(t--)
    {
        mp.clear();
        int n;
        cin>>n;
        int flag=0;
        for(int i=1;i<=n;i++)
        {   int x;
            cin>>x;
            if(mp[x]&&mp[x]!=i-1)
            {
                flag=1;
                
            }
            else if(!mp[x]) mp[x]=i;
        }
        if(flag) puts("YES");
        else puts("NO");
    }
   //system("pause");
   return 0;
}
