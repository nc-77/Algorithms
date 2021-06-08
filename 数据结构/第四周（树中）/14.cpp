#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
map<char,int>cnt;
priority_queue<int,vector<int>,greater<int>>que;
map<char,string>code;
int cul()
{
    int sum=0;
    int x=0,y=0;
    while(!que.empty())
    {
        if(que.size()==1) break;
        x=que.top();
        que.pop();
        y=que.top();
        que.pop();
        que.push(x+y);
        sum+=(x+y);
    }
    return sum;
}
struct node
{
    int flag;
    node *left,*right;
};
bool check(string s,node *T)
{
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0'){
            if(!T->left){
                node *tmp=new node;
                tmp->left=tmp->right=nullptr;
                tmp->flag=0;
                T->left=tmp;
            }
            else{
                if(T->left->flag) {return false;}
            }
            T=T->left;
        }
        else{
            if(!T->right){
                node *tmp=new node;
                tmp->left=tmp->right=nullptr;
                tmp->flag=0;
                T->right=tmp;
            }
            else{
                if(T->right->flag) {return false;}
            }
            T=T->right;
        }
    }
    if(T->right||T->left) return false;
    T->flag=1;
    return true;

}
int main()
{
   int n,q;
   cin>>n;
   char ed;
   for(int i=0;i<n;i++)
    {
        char ch;
        int x;
        cin>>ch>>x;
        cnt[ch]=x;
        que.push(x);
        if(i==n-1) ed=ch;
    }
    int ans=cul();
    cin>>q;
    while(q--)
    {
        int flag=1;
        code.clear();
        int res=0;
        char ch;string s;
        node *root=new node;
        root->left=root->right=nullptr;
        while(cin>>ch>>s)
        {
             res+=s.size()*cnt[ch];
             code[ch]=s;
             if(!check(s,root)) flag=0;
            if(ch==ed) break;
        }
        if(flag&&res==ans) puts("Yes");
        else puts("No");
    }
   return 0;
}
