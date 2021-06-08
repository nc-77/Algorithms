#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll a[maxn],b[maxn];
int main()
{
   
//   system("pause");
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        int c1=1,c2=n;
        for(int i=1;i<=n;i++)
        {
            if(i%2) b[i]=a[c1++];
            else b[i]=a[c2--];
             
        }
        for(int i=n;i>=1;i--)
        cout<<b[i]<<" ";
        cout<<endl;
    }
   return 0;
}
