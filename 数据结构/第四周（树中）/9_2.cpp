#include<iostream>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int a[150];
struct node
{
    int data;
    int flag;
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
bool check(node *T,int x)
{
    if(!T) return true;
    if(T->flag)
    {
        if(x<T->data) check(T->left,x);
        else if(x>T->data) check(T->right,x);
        else return true;
    }
    else{
        if(x==T->data) {
            T->flag=1;
            return true;
        }
        else return false;
    }
}
void free(node *T)
{
    if(!T) return;
    free(T->left);
    free(T->right);
    delete T;
}
void Resetflag(node *T)
{
    if(!T) return;
    T->flag=0;
    Resetflag(T->left);
    Resetflag(T->right);
}
int main()
{
   int n,l;
   while(cin>>n&&n)
   {
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
           int flag=1;
           for(int i=0;i<n;i++) {
               int x;
               cin>>x;
               if(!check(T,x)) flag=0;
           }
           if(flag) puts("Yes");
           else puts("No");
           Resetflag(T);
       }
       free(T);
   }
   return 0;
}
