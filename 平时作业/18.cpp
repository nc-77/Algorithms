#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
struct node
{
    node *L,*R;
    int val;
};
int par[1050],lev[1050];
void insert(int x,node *&root,int Lev)
{
    if(!root){
        root=new node;
        root->val=x;
        mp[x]=root;
        par[x]=-1;
        lev[x]=0;
        return;
    }
    if(x<root->val){
        if(!root->L) {
            root->L=new node;
            root->L->val=x;
            root->L->L=root->L->R=nullptr;
            
            par[x]=root->val;
            lev[x]=Lev;
        }
        else insert(x,root->L,Lev+1);
    }
    else{
        
        if(!root->R) {
            root->R=new node;
            root->R->val=x;
            root->R->L=root->R->R=nullptr;
            
             par[x]=root->val;
             lev[x]=Lev;
        }
        else insert(x,root->R,Lev+1);
    }
}
int main()
{
   int n;
   cin>>n;
   node *root=nullptr;
   for(int i=0;i<n;i++){
       int x;
       cin>>x;
       insert(x,root,0);
       debug(root->val);
   }
   int m;
   cin>>m;
   getchar();
   while(m--)
   {
       int A,B;
       scanf("%d",&A);
       string sec;
        cin>>sec;
        if(sec=="and"){
            
            getchar();
            scanf("%d",&B);
            string nothing,s;
            cin>>nothing>>s;
            if(s=="siblings"){
                if(par[A]==par[B]) puts("Yes");
                else puts("No");
            }
            else{
                string s;
                getline(cin,s);
                if(lev[A]==lev[B]) puts("Yes");
                else puts("No");
            }
        }
        else{
            string nothing,s;
            cin>>nothing>>s;
            if(s=="root"){
                if(A==root->val) puts("Yes");
                else puts("No");
            }
            else if(s=="parent"){
                cin>>nothing;
                getchar();
                scanf("%d",&B);
                node *par=mp[A];
                if(par->L&&par->L->val==B||par->R&&par->R->val==B) puts("Yes");
                else puts("No");
            }
            else if(s=="left"){
                cin>>nothing>>nothing;
                getchar();
                scanf("%d",&B);
                node *par=mp[B];
                if(par->L&&par->L->val==A) puts("Yes");
                else puts("No");
            }
            else if(s=="right"){
                cin>>nothing>>nothing;
                getchar();
                scanf("%d",&B);
                node *par=mp[B];
                if(par->R&&par->R->val==A) puts("Yes");
                else puts("No");
            }
        }
   }
   

   return 0;
}
