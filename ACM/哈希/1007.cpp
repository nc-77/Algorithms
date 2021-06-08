#include<iostream>
#include<map>
#include<queue>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
map<string,string>mp;
struct node {
    string pos;
    //string ans;
    int x;
    int y;
}cur,nex;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
char d[]={'r','l','d','u'};

void bfs()
{
    node st;
    st.pos=" 12345678x";
    st.x=st.y=3;
    //st.ans="";
    mp.clear();
    queue<node>que;
    que.push(st);
   // mp[st.pos]="";
    while(!que.empty())
    {
        cur=que.front();
        que.pop();
        for(int i=0;i<4;i++)
        {
            nex.x=cur.x+dx[i],nex.y=cur.y+dy[i];
            if(nex.x<1||nex.x>3||nex.y<1||nex.y>3) continue;
            string pos=cur.pos;
            swap(pos[(cur.x-1)*3+cur.y],pos[(nex.x-1)*3+nex.y]);
            nex.pos=pos;
            
            if(mp[nex.pos]==""){
               mp[nex.pos]=mp[cur.pos]+d[i];
                que.push(nex);
                
            }
            
        }
    }
   
}
int main()
{
   //ios::sync_with_stdio(false);
    char t[100];
    bfs();
   while(gets(t))
   {
       
        string s=" ";
        for(int i=0;i<=20;i++) 
        {
            if(t[i]>='1'&&t[i]<='8'||t[i]=='x')
            {
                s+=t[i];
                
            }
            
        }
        if(mp[s]!="") 
        {
            string ans=mp[s];
            for(int i=ans.size()-1;i>=0;i--)
            {
                if(ans[i]=='l') cout<<"r";
                else if(ans[i]=='r') cout<<"l";
                else if(ans[i]=='d') cout<<"u";
                else cout<<"d";
            }
            cout<<endl;
        }
        else  cout<<"unsolvable"<<endl;
   }
   
   //system("pause");
   return 0;
}
