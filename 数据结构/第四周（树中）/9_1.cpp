#include<iostream>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
node * insert(int x,node * &root)
{
    if(!root){
        root=new node;
        root->data=x;
        root->left=root->right=nullptr;
    }
    else{
        if(x<root->data)
        root->left=insert(x,root->left);
        else if(x>root->data)
        root->right=insert(x,root->right);
    }
    return root;
}
bool same(node *T,node *t)
{
    if(!T||!t) return true;
    if(T->data!=t->data)
    return false;
    if(!same(T->left,t->left)) return false;
    if(!same(T->right,t->right)) return false;
    return true;
}
void free(node *T)
{
    if(!T) return;
    free(T->left);
    free(T->right);
    delete T;
}
int main()
{
   int n,l;
   while(cin>>n)
   {
       if(!n) break;
       cin>>l;
       node *T=nullptr;
       for(int i=0;i<n;i++)
       {
           int x;
           cin>>x;
            insert(x,T);
       }
        while(l--)
        {
            node *t=nullptr;
             for(int i=0;i<n;i++)
            {
                int x;
                cin>>x;
                insert(x,t);
            }
            if(same(T,t)) puts("Yes");
            else puts("No");
            free(t);
        }
        free(T);
   }
   return 0;
}
