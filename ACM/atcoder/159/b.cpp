#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
bool fun(string s)
{
    string rev=s;
    reverse(s.begin(),s.end());
    if(s==rev) return true;
    return false;
}
int main()
{
   string s;
   cin>>s;
   int n=s.size();
   if(n%2==0) 
   {
       cout<<"No"<<endl;
       return 0;
   } 
   int flag=0;
   string s1=s.substr(0,(n-1)/2);
   string s2=s.substr((n+3)/2-1);
   if(fun(s)&&fun(s1)&&fun(s2)) flag=1; 
   if(flag) cout<<"Yes";
   else cout<<"No";
   //system("pause");
   return 0;
}
