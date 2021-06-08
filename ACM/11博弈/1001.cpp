#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e3+10;
int sg[maxn];
int main()
{
   //ios::sync_with_stdio(false);
   for(int i=1;i<=1000;i++)
    for(int j=0;(1<<j)<=i;j++)
    {
        if(sg[i-(1<<j)]==0)
        {
            sg[i]=1;
            break;
        }
    }
    int n;
    while(cin>>n)
    {
        if(sg[n]) cout<<"Kiki"<<endl;
        else cout<<"Cici"<<endl;
    }
   //system("pause");
   return 0;
}
