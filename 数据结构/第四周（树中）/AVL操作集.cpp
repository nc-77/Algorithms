#include<iostream>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
typedef struct Tnode* AVLTree;
struct Tnode
{
    int data;
    Tnode *left,*right;
    int height;
};
int getHeight(AVLTree T){
    if(!T) return 0;
    else return T->height;
}
AVLTree LL_rotation(AVLTree A)
{
    AVLTree B=A->left;
    A->left=B->right;
    B->right=A;
    A->height=max(getHeight(A->right),getHeight(A->left))+1;
    B->height=max(A->height,getHeight(B->left))+1;
    return B;
}
AVLTree RR_rotation(AVLTree A)
{
    AVLTree B=A->right;
    A->right=B->left;
    B->left=A;
    A->height=max(getHeight(A->right),getHeight(A->left))+1;
    B->height=max(A->height,getHeight(B->right))+1;
    return B;
}
AVLTree LR_rotation(AVLTree A)
{
    A->left=RR_rotation(A->left);
    return LL_rotation(A);
}
AVLTree RL_rotation(AVLTree A)
{
    A->right=LL_rotation(A->right);
    return RR_rotation(A);
}
AVLTree insert(int x,AVLTree T)
{
    if(!T){
        T=new Tnode;
        T->data=x;
        T->height=0;
        T->left=T->right=nullptr;
    }
    else if(x<T->data){
        T->left=insert(x,T->left);
        if(abs(getHeight(T->left)-getHeight(T->right))>=2) //需要左旋
        {
            if(x<T->left->data) //左单旋
            T=LL_rotation(T);
            else T=LR_rotation(T); //左右双旋
        }
    }
    else{
        T->right=insert(x,T->right);
        if(abs(getHeight(T->left)-getHeight(T->right))>=2) //需要右旋
        {
            if(x>T->right->data) //右单旋
            T=RR_rotation(T); 
            else T=RL_rotation(T); //右左双旋
        }
    }
    T->height=max(getHeight(T->right),getHeight(T->left))+1;
    return T;
}
int main()
{
   int n;
   cin>>n;
   AVLTree T=nullptr;
   for(int i=0;i<n;i++)
   {
       int x;
       cin>>x;
       T=insert(x,T);
   }
   cout<<T->data<<endl;
   return 0;
}
