#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
vector<int>g;
int main()
{
   //ios::sync_with_stdio(false);
   int m,n;
   while(cin>>m>>n)
   {
       g.clear();
       if(m%(n+1)==0) cout<<"none"<<endl;
       else 
       {
           for(int i=1;i<=n;i++)
           {
               if(i>=m||(m-i)%(n+1)==0) 
               g.push_back(i);
           }
           for(int i=0;i<g.size();i++)
           {
               cout<<g[i];
               if(i==g.size()-1) cout<<endl;
               else cout<<" ";
           }
       }
       
   }
   //system("pause");
   return 0;
}
