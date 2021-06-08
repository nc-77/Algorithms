#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=1e4+10;
int sg[maxn],s[105];
bool vis[maxn];
void getsg(int k)
{
    set0(sg);
    for(int i=0;i<=10000;i++)
    {
        set0(vis);
        for(int j=1;j<=k;j++)
        {
            if(i-s[j]>=0)
            vis[sg[i-s[j]]]=1;
        }
        for(int j=0;;j++){
            if(!vis[j])
            {
                sg[i]=j;
                break;
            }
        }
    }
}
int main()
{
   ios::sync_with_stdio(false);
   int k;
   while(cin>>k&&k)
   {
       for(int i=1;i<=k;i++) cin>>s[i];
       getsg(k);
       int q;cin>>q;
       while(q--)
       {
           int n;cin>>n;
           int sum=0,x;
           for(int i=1;i<=n;i++) {
               cin>>x;sum^=sg[x];}
            if(sum==0) cout<<"L";
            else cout<<"W";
       } 
       cout<<endl;
   }
   //system("pause");
   return 0;
}
