#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int main()
{
   int n;
   cin>>n;
   getchar();
   for(int i=0;i<n;i++)
   {
       string s;
       getline(cin,s);
        for(int i=s.size()-1;i>=0;i--){
            cout<<s[i];

        }
        cout<<endl;
   }
   return 0;
}
