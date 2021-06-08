#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],b[maxn];
int main()
{
   int t;
   cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int flag=1;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) 
        {
            cin>>b[i];
            b[i]-=a[i];
            if(b[i]<0) flag=0;
        }
        b[0]=0,b[n+1]=0;
        int cnt=0;
        for(int i=1;i<=n+1;i++)
        {
            if(b[i]!=b[i-1])
            cnt++;
        }
        if(cnt>2) flag=0;
        if(flag) puts("YES");
        else puts("NO");
    }
   //system("pause");
   return 0;
}
