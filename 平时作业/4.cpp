#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
const int maxn=1e6+10;
struct Node
{
    int nex;
    int value;
    int address;
}node[maxn];

map<int,int>vis;

void insert(vector<Node>&List,Node x){
    int len=List.size();
    if(len){
        List[len-1].nex=x.address;
        x.nex=-1;
        List.push_back(x);
        
    }
    else{
        x.nex=-1;
        List.push_back(x);
    }
}

void print(vector<Node>&g){
    for(Node x:g)
    {
        if(x.nex!=-1)
        printf("%05d %d %05d\n",x.address,x.value,x.nex);
        else
        printf("%05d %d -1\n",x.address,x.value);
    }
    
    //cout<<address<<" "<<node[address].value<<" "<<node[address].nex<<endl;
}
int main()
{
   int first,n;
   int address,val,nex;
   cin>>first>>n;
   
    for(int i=0;i<n;i++)
    {
        cin>>address;
        node[address].address=address;
        cin>>node[address].value;
        cin>>node[address].nex;
    }
    int p=first;
    vector<Node>g; // 初始化
    vector<Node>res,del; //去重后 和 删除的
    while(1)
   {
       int nexadd=node[p].nex;
       
       insert(g,node[p]);
       if(nexadd==-1) break;
        p=nexadd;
   }
   p=first;
    while(1){
        int val=abs(node[p].value);
        int nexadd=node[p].nex;
        
        if(vis[val]){
            
            insert(del,node[p]);
        }
        else{
            vis[val]=1;
            insert(res,node[p]);
        }
        if(nexadd==-1) break;
        p=nexadd;
    }
    print(res);
    print(del);
   
   return 0;
}
