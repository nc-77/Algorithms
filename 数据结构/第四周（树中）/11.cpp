#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
vector<int>pre;
struct node
{
    int Data;
    node* Left,*Right;
};
int pow(int x,int n)
{
	int res=1;
	while(n)
	{
		if(n&1) res=res*x;
		x=x*x;
		n>>=1;
	}
	return res;
}
void work(vector<int>g)
{
    int n=g.size();
    if(n==1){
        pre.push_back(g[0]);
        return;
    }
    if(n==0) return;
    int t=n,k=0;
    while(1)
    {
       if(t<pow(2,k)) break;
       t-=pow(2,k);
       k++;
    }
    sort(g.begin(),g.end());
    int m=(n-1-t)/2;
    int index=m+min(t,pow(2,k-1));
    pre.push_back(g[index]);
    vector<int>L(g.begin(),g.begin()+index);
    vector<int>R(g.begin()+index+1,g.end());
    work(L);
    work(R);
}
node* Insert(node* BST, int X)
{
    if(!BST){
        BST=new node;
        BST->Data=X;
        BST->Left=BST->Right=NULL;
    }
    else{
        if(X>BST->Data) BST->Right=Insert(BST->Right,X);
        else if(X<BST->Data) BST->Left=Insert(BST->Left,X);
    }
    return BST;
}
void bfs()
{
    node *T=nullptr;
    for(int i=0;i<pre.size();i++)
    T=Insert(T,pre[i]);
    queue<node*>q;
    q.push(T);
    int f=1;
    while(!q.empty())
    {
        node* x=q.front();
        q.pop();
        if(f) {cout<<x->Data;
        f=0;}
        else cout<<" "<<x->Data;
        if(x->Left) q.push(x->Left);
        if(x->Right) q.push(x->Right);
    }
}
int main()
{
   int n;
   cin>>n;
   vector<int>g;
   for(int i=0;i<n;i++)
   {
       int x;
       cin>>x;
       g.push_back(x);
   }
   work(g);
   bfs();
   return 0;
}
