#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<vector>
#include<map>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
vector<char>ans;
string s1,s2;
stack<char>s;
void postorder(string s1,string s2)
{
    if(!s1.size()) return;
    int pos=s2.find(s1[0]);
    postorder(s1.substr(1,pos),s2.substr(0,pos));
   postorder(s1.substr(pos+1),s2.substr(pos+1));
     ans.push_back(s1[0]);
}
map<int,char>mp;
map<char,int>hy;
int main()
{
    for(int i=0;i<=30;i++)
    {
        if(i<10) mp[i]='0'+i;
        else mp[i]='a'+i-10;
    }
    for(auto x:mp){
        hy[x.second]=x.first;
    }
   int n;
   cin>>n;
   getchar();
   for(int i=0;i<n+n;i++)
   {
       char op[10];
       scanf("%s",op);
        if(op[1]=='u') {
            int x;
            cin>>x;
            s1+=mp[x];
            s.push(mp[x]);
        }
        else {
            s2+=s.top();
            s.pop();
        }
   }
   postorder(s1,s2);
   for(int i=0;i<ans.size();i++)
   {
       if(i!=ans.size()-1)
       cout<<hy[ans[i]]<<" ";
       else 
       cout<<hy[ans[i]];
   }
    return 0;
}
