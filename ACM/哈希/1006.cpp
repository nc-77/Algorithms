#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
map<int,int>mp;
int main()
{
   //ios::sync_with_stdio(false);
   int n;
   while(cin>>n)
   {
       mp.clear();
       string ans;
       int mx=-1;
       for(int i=1;i<=n;i++)
        {
            int s;
            scanf("%d",&s);
            mp[s]++;
            if(mp[s]>mx){
                mx=mp[s];
                ans=s;
            }
        }
        cout<<mx<<endl;
   }
   
   //system("pause");
   return 0;
}
