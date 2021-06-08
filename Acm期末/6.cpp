#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
struct Node{
	int data;
	Node *left;
	Node *right;
};
struct Tree{
	Node *root;
};
int a[maxn];
void insert_Node(Tree *tree, int value)
{
	Node *node=new Node;
	node->data=value;
	node->left=NULL;
	node->right=NULL; 
	
	if (tree->root==NULL){
		tree->root=node;
	}else{
		Node *tmp=tree->root;
		while (tmp!=NULL){
			if (value<tmp->data){
				if (tmp->left==NULL){
					tmp->left=node;
					return;
				}else{
					tmp=tmp->left;
				}
			}else{
				if (tmp->right==NULL){
					tmp->right=node;
					return;
				}else{
					tmp=tmp->right;
				}
			}
		}
	}
} 

void print(Node *node)
{
	queue<Node *>q;
	q.push(node);
	while(!q.empty())
	{
		Node *cur=q.front();
		q.pop();
		cout<<cur->data<<" ";
		
		if(cur->left!=nullptr)q.push(cur->left);
		if(cur->right!=nullptr)q.push(cur->right);
	}
}
int main()
{
   
   int n;
    while(cin>>n){
       for(int i=1;i<=n;i++)
       cin>>a[i];
       Tree tree;
       tree.root=nullptr;
       for(int i=1;i<=n;i++)
       {
           insert_Node(&tree,a[i]);
       }
       print(tree.root);

       cout<<endl;
   }
   
   return 0;
}
