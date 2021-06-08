#include<iostream>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
typedef struct Node* list;
const int maxn=1e6+10;
struct Node
{
    int address,data,nexaddress;
    list Next;
};
int nex[maxn],data[maxn];
void print(list head)
{
    list p=head->Next,q=p;
    while(p){
        if(p->nexaddress!=-1)
        printf("%05d %d %05d\n",p->address,p->data,p->nexaddress);
        else
        printf("%05d %d -1\n",p->address,p->data);
        p=p->Next;
        delete q;
        q=p;
    }
    delete head;
}
list reverse_list(list head,int k){
    list p=head->Next,q=p->Next,t;
    while(--k){
        t=q->Next;
        q->Next=p;
        q->nexaddress=p->address;
        p=q;
        q=t;
    }
     head->Next->Next=q;
    if(!q) head->Next->nexaddress=-1;
    else head->Next->nexaddress=q->address;
    return p;
}
int main()
{
   int head_address,n,k;
   cin>>head_address>>n>>k;
   for(int i=0;i<n;i++)
   {
       int pos;cin>>pos;
       cin>>data[pos]>>nex[pos];
   }
   list head=new Node;
   head->nexaddress=head_address;
   list p=head,q;
   int num=0;
    while(1)
    {
        if(p->nexaddress==-1){
            p->Next=nullptr;
            break;
        }
        q=new Node;
        q->address=p->nexaddress;
        q->nexaddress=nex[q->address];
        q->data=data[q->address];
        p->Next=q;
        p=q;
        num++;
    }
    list a=head;
    for(int i=0;i<(num/k);i++)
    {
        list snode=reverse_list(a,k);
        a->Next=snode;
        a->nexaddress=snode->address;
        int cnt=k;
        while(cnt--){
            a=a->Next;
        }
    }
    print(head);
   //system("pause");
   return 0;
}
