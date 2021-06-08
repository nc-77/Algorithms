#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e2+10;
int a[maxn];
int main()
{
   //ios::sync_with_stdio(false);
   int n;
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
   sort(a+1,a+n+1);
   int flag=0;
   for(int i=1;i<=n-2;i++)
    for(int j=i+1;j<=n-1;j++)
        for(int k=j+1;k<=n;k++)
        {
            if(a[i]+a[j]>a[k]) {
                flag=1;
                cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
                return 0;
            }
        }
        if(!flag) cout<<"No solution"<<endl;
   //system("pause");
   return 0;
}
