#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
map<char,int>mp;
char s[maxn];
int main()
{
   ios::sync_with_stdio(false);
   
   while(gets(s))
   {
       mp.clear();
       for(int i=0;s[i]!='\0';i++)
       {
           mp[s[i]]++;
       }
        for(int i=0;i<26;i++)
        {
            cout<<char(i+'a')<<":";
            cout<<mp[char(i+'a')]<<endl;
        }
        cout<<endl;
   }
   //system("pause");
   return 0;
}
