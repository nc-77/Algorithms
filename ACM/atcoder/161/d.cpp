#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll dp[maxn];
int main()
{
   ll n;
   cin>>n;
    queue<string>que;
    for(int i=1;i<=9;i++)
    {
        string s=to_string(i);
        que.push(s);
    }
    int cnt=0;
    while(!que.empty())
    {
        string cur=que.front();
        que.pop();
        int len=cur.size();
        cnt++;
        if(cnt==n) {
            cout<<cur<<endl;
            return 0;
        }
        int x=cur[len-1]-'0';
        if(x==0) que.push(cur+"0"),que.push(cur+"1");
        else if(x==9) que.push(cur+"8"),que.push(cur+"9");
        else 
        {
            que.push(cur+to_string(x-1));
            que.push(cur+to_string(x));
            que.push(cur+to_string(x+1));
        }
    }
   //system("pause");
   return 0;
}
