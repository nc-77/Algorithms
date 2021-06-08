#include<iostream>
#include<vector>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
struct tree{
    char root;
    tree *l;
    tree *r;
};
vector<tree *>address;
tree *dfs(string p1,string p2)
{
   
    tree *Tree=new tree;
    if(p1.size()==0) return nullptr;
    
    int index=p2.find(p1[0]);
    Tree->root=p1[0];
    Tree->l=dfs(p1.substr(1,index),p2.substr(0,index));
    Tree->r=dfs(p1.substr(index+1),p2.substr(index+1));
    address.push_back(Tree);
    return Tree;
}
vector<char>ans;
void houxu(tree *Tree){
    
    if(Tree==nullptr) return;
    
    houxu(Tree->l);
    houxu(Tree->r);
    ans.push_back(Tree->root);
}
int main()
{
   //ios::sync_with_stdio(false);
   int n;
   while(cin>>n)
   {
       string p1,p2;
        for(int i=0;i<n;i++) {
            char x;
            cin>>x;
            p1+=x;
        
        }
        for(int i=0;i<n;i++) {
            char x;
            cin>>x;
            p2+=x;
        }
       
        ans.clear();
        address.clear();
        houxu(dfs(p1,p2));
        for(int i=0;i<address.size();i++){
            delete(address[i]);
        }
        cout<<ans[0];
        for(int i=1;i<ans.size();i++){
            cout<<" "<<ans[i];
        }
   }
   
   //system("pause");
   return 0;
}
