#include<iostream>
#include<map>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
char ID[15];
struct node
{
    char l,r;
};
void solve(int n,map<char,node>&a)
{
    for(int i=0;i<n;i++)
   {
       char id,l,r;
       cin>>id>>l>>r;
        ID[i]=id;
        a[id].l=l;
        a[id].r=r;
   }
   for(int i=0;i<n;i++)
   {
       if(a[ID[i]].l!='-')a[ID[i]].l=ID[a[ID[i]].l-'0'];
       if(a[ID[i]].r!='-')a[ID[i]].r=ID[a[ID[i]].r-'0'];
       
   }
}
int main()
{
   int n;
    cin>>n;
   map<char,node>a;
    map<char,node>b;
    solve(n,a);
    int m;
    cin>>m;
    solve(m,b);
    if(n!=m) {
        cout<<"No"<<endl;
        return 0;
    }
    int flag=1;
    for(int i=0;i<m;i++)
    {
        char ls=a[ID[i]].l,rs=a[ID[i]].r,_ls=b[ID[i]].l,_rs=b[ID[i]].r;
        //cout<<ls<<" "<<rs<<" "<<_ls<<" "<<_rs<<endl;
        if(ls==_ls&&rs==_rs||ls==_rs&&rs==_ls) continue;
        else flag=0;
    }
    cout<<(flag?"Yes":"No")<<endl;
   return 0;
}
