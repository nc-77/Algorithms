#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[100],vis[1050],sg[1050];
void getsg(){
    for(int i=0;i<=1005;i++)
    {
        set0(vis);
        for(int j=1;i>=a[j]&&j<=20;j++)
        vis[sg[i-a[j]]]=1;
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
   //ios::sync_with_stdio(false);
   a[1]=1,a[2]=2;
   for(int i=3;i<=20;i++)
   a[i]=a[i-1]+a[i-2];
   getsg();
   int a,b,c;
   while(cin>>a>>b>>c)
   {
       if(!a&&!b&&!c) break;
       if((sg[a]^sg[b]^sg[c])==0) cout<<"Nacci"<<endl;
       else cout<<"Fibo"<<endl;
   }
   //for(int i=0;i<=100;i++) debug(i),debug(sg[i]);
   //system("pause");
   return 0;
}
