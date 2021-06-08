#include<iostream>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;


void preorder(int *hou,int *zhong,int n){
    if(n<=0) return;
    int root=hou[n-1];
    cout<<" "<<root;
    int pos;
    for(int i=0;i<n;i++){
        if(zhong[i]==root){
            pos=i;
            break;
        }
    }
    preorder(hou,zhong,pos);
    preorder(hou+pos,zhong+pos+1,n-pos-1);
}
int main()
{
    int n;
   cin>>n;
   int hou[35],zhong[35];
    
   for(int i=0;i<n;i++) cin>>hou[i];
   for(int i=0;i<n;i++) cin>>zhong[i];
   
   cout<<"Preorder:";
   preorder(hou,zhong,n);
   return 0;
}
