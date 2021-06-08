#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int tar,ans[10],flag,vis[100];
string s;
bool cmp(char a,char b){
    return a>b;
}
void dfs(int x)
{
    if(x>6||flag) return;
    if(x==6){
        if(ans[1]-pow(ans[2],2)+pow(ans[3],3)-pow(ans[4],4)+pow(ans[5],5)==tar)
        {
            flag=1;
            for(int i=1;i<=5;i++) cout<<char(ans[i]+'A'-1);
            cout<<endl;
            return;
        }
    }
    for(int i=0;i<s.size();i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            ans[x]=s[i]-'A'+1;
            dfs(x+1);
            vis[i]=0;
        }
    }

}
signed main()
{
   while(cin>>tar>>s)
   {
       if(tar==0&&s=="END") break;
       if(s.size()<5)
       {
           cout<<"no solution"<<endl;
           continue;
       }
       
       flag=0;
       sort(s.begin(),s.end(),cmp);
       
       dfs(1);
       
       
       if(!flag) cout<<"no solution"<<endl;
   }
   //system("pause");
   return 0;
}
