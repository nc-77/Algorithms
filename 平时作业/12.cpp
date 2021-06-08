#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int main()
{
   string s;
   cin>>s;
   int cnt=0;
   int ans=0;
   vector<int>g;
   
   s+=' ';
   for(int i=0;i<33;i++)
   {
       if(cnt==8){
           cnt=0;
           g.push_back(ans);
            ans=0;
            
       }
        {
           cnt++;
           if(s[i]=='1'){
               ans+=(1<<(7-(i%8)));
               //debug((1<<(7-(i))));
           }
       }
   }
   for(int i=0;i<=3;i++){
       if(i!=3)cout<<g[i]<<'.';
       else cout<<g[i];
   }
   return 0;
}
