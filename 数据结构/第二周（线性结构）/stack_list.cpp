#include<iostream>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
template<class ElementType> 
class stack
{
private:
    struct node
    {
        ElementType Data;
        node *next;
    };
    node *head;
public:
    stack(); 
    ~stack();
    void push(ElementType item);
    ElementType pop();
};
template<class ElementType>
stack<ElementType>::stack()
{
    head=new node;
    head->next=nullptr;
}
template<class ElementType>
stack<ElementType>::~stack()
{
    node* p=head;
    while(p){
        p=p->next;
        delete p;
    }
    delete head;
}
template<class ElementType>
void stack<ElementType>::push(ElementType item)
{
    node* tmp=new node;
    tmp->Data=item;
    tmp->next=head->next;
    head->next=tmp;
}
template<class ElementType>
ElementType stack<ElementType>::pop()
{
    if(head->next==nullptr){
       cout<<"failed pop because stack is empty"<<endl;
        return NULL;
    }
    else {
        node* cell=head->next;
        ElementType res=cell->Data;
        head->next=cell->next;
        delete cell;
        return res;
    }
}
int main()
{
   stack<int>s;
   for(int i=0;i<10;i++)
   s.push(i);
   for(int i=0;i<10;i++)
   {
       cout<<s.pop()<<endl;
   }
   s.pop();
   //system("pause");
   return 0;
}
