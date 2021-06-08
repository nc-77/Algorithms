#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;
int mp[30];
set<int>g[30];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {   int flag=1,num=0;
        int a[1000];
        int ans[30];
        memset(ans,-1,sizeof(ans));
        set0(mp);
        set0(a);
        string s;
        cin>>s;
        if(s.size()==1)
        {   puts("YES");
            for(int i=0;i<26;i++)
                cout<<char('a'+i);
            cout<<endl;
            continue;
        }
        for(int i=0;i<30;i++)
            g[i].clear();
        for(int i=0;i<s.size()-1;i++)
        {
            g[s[i]-'a'].insert(s[i+1]-'a');
            mp[s[i]-'a']=1;

        }
        for(int i=1;i<s.size();i++)
        {
            g[s[i]-'a'].insert(s[i-1]-'a');
            mp[s[i]-'a']=1;
        }
        for(int i=0;i<=26;i++)
        {
            if(g[i].size()>2) flag=0;
            if(g[i].size()==1)
            {
                num++;
                a[num]=i;
            }
        }
         if(num!=2)  flag=0;
         ans[0]=a[1];
         if(flag==0)
         {
             puts("NO");
             continue;
         }
         else puts("YES");
         set<int>::iterator it;
         it=g[a[1]].begin();

        ans[1]=*it;

        if((g[*it].size()!=1))
        {
            for(int i=2;i<=s.size();i++)
        {   it=g[*it].begin();
            if(*it!=ans[i-2])
            ans[i]=*it;
            else
            {
                ans[i]=*(++it);
            }
            if(g[ans[i]].size()==1)
                break;
        }
        }

        for(int i=0;i<26;i++)
        {
            if(ans[i]!=-1)
            cout<<char(ans[i]+'a');
            else
            break;
        }
        for(int i=0;i<26;i++)
        {
            if(!mp[i]) cout<<char('a'+i);
        }
        cout<<endl;
    }
}
