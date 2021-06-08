#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
string add(string a, string b){
    string c;
    if(a.size() > b.size()) swap(a, b);
    int len = min(a.size(), b.size());
    int f = 0;
    for(int i = len - 1, j = b.size() - 1; i >= 0; i--, j--){
        c += ((a[i] - '0' + b[j] - '0' + f) % 10) + '0';
        f = (a[i] - '0' + b[j] - '0' + f) / 10;
    }
    for(int j = b.size() - a.size() - 1; j >= 0; j--){
        c += ((b[j] - '0' + f) % 10) + '0';
        f = (b[j] - '0' + f) / 10;
    }
    if(f){
        c += '1';
    }
    reverse(c.begin(), c.end());
    return c;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       string s;
       cin>>s;
       if(s.size()>20)cout<<"Zhang San will never have girlfriend!"<<endl;
       else 
       {
           cout<<add(s,"1")<<endl;
       }
   }
   //system("pause");
   return 0;
}
