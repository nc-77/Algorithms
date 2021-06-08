#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   int n,m,k;
   cin>>n>>m>>k;
   int x,y;
   for(int i=1;i<=k;i++) cin>>x>>y;
   for(int i=1;i<=k;i++) cin>>x>>y;
   cout<<n+m+n*m-3<<endl;
   for(int i=1;i<n;i++) cout<<"U";
   for(int i=1;i<m;i++) cout<<"L";
    for(int i=1;i<m;i++) cout<<"R";
    for(int i=1;i<n;i++)
    {
        cout<<"D";
        for(int j=1;j<m;j++)
        if(i%2)cout<<"L";
        else cout<<"R";
    }
   //system("pause");
   return 0;
}
