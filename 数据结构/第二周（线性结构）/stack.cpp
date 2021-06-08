#include<iostream>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
template<class ElementType>
class stack
{
private:
    int top;
    int maxsize;
    ElementType *Data; 
public:
    stack(int m_size);
    ~stack() {delete []Data;}
    void push(ElementType item);
    ElementType pop();
};
template<class ElementType>
stack<ElementType>::stack(int m_size)
{   
    top=-1;
    maxsize=m_size;
    Data=new ElementType[maxsize];
}
template<class ElementType>
void stack<ElementType>::push(ElementType item)
{
    if(top==maxsize-1)
    cout<<"failed push because stack is full"<<endl;
    else {
        Data[++top]=item;
    }
}
template<class ElementType>
ElementType stack<ElementType>::pop()
{
    if(top==-1){
        cout<<"failed pop because stack is empty"<<endl;
        return NULL;
    }
    else{
        return Data[top--];
    }
}
int main()
{
   stack<int>s(10);
   s.pop();
   s.push(1);
   s.push(10);
   cout<<s.pop()<<endl;

   //system("pause");
   return 0;
}
