#include<bits/stdc++.h>
#include <vector> 
using namespace std;
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}tree;
vector<vector<int>> v;
tree* Createtree(int dataroot)
{
    tree* head;
    head=new tree;
    (*head).data=dataroot;
    head->left=NULL;
    head->right=NULL;
    return head;
}
void Inserttree(tree* head,int n)
{
    if(n>head->data)
    {
        if(head->right)
        {
            Inserttree(head->right,n);
        }
        else
        {
            tree* New=new tree;
            (*New).data=n;
            New->left=NULL;
            New->right=NULL;
            head->right=New;
            return;
        }
    }
    else
    {
        if(head->left)
        {
            Inserttree(head->left,n);
        }
        else
        {
            tree* New=new tree;
            (*New).data=n;
            New->left=NULL;
            New->right=NULL;
            head->left=New;
            return;
        }
    }
}
vector<vector<int> > Layer_tree(tree* head)
{
    if(!head) 
        return v;
    layertree(head,0);
    
    return v;
}
void layertree(tree* head,int n)
{
    if(!head) return;
    if(n>=v.size())
    {
        vector<int> x;
        v.push_back(x);
    } 
    v[n].push_back(head->data);
    layertree(head->left,n+1);
    layertree(head->right,n+1);
}
void Point()
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
    }
}
int main ()
{
    int dataroot;
    int n;
    while(cin>>n)
    {
        v.clear();
        cin>>dataroot; 
        tree* root;
        root->data=0;
        root=Createtree(dataroot);
        for(int i=1;i<n;i++)
        {
            int a;
            cin>>a;
            Inserttree(root,a);
        }
        v=Layer_tree(root);
        Point();
        cout<<endl;
    }
    
}
