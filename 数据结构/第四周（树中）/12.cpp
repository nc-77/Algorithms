#include<iostream>
#define debug(x) cout<<#x<<'='<<x<<endl
#define MINdata -1 //哨兵
#define ls index*2
#define rs index*2+1
using namespace std;
class MinHeap
{
private:
    int size;
    int Maxsize;
    
public:
    int *data;
    MinHeap(int maxsize);
    ~MinHeap() {delete []data;}
    bool empty(){return size==0;};
    bool push(int x);
    int  pop();
    void down(int index);
    void buildHeap(int *m_data,int k);// data按任意序列已存放  o(n)建堆
};
MinHeap::MinHeap(int maxsize)
{
    Maxsize=maxsize;
    size=0;
    data=new int[Maxsize+1];
    data[0]=MINdata;
}
bool MinHeap::push(int x)
{
    if(size==Maxsize) return false;
    int index=++size;
    while(data[index/2]>x)
    {
        data[index]=data[index/2];
        index/=2;
    }
    data[index]=x;
    return true;
}
void MinHeap::down(int index)
{
    while(1)
    {
        int st=index;
        if(rs<=size){
            int ms=data[ls]<data[rs]?ls:rs;
            if(data[index]>data[ms]) {
                swap(data[index],data[ms]);
                index=ms;
            }
        }
        else if(ls<=size){
            if(data[index]>data[ls]) {
                swap(data[index],data[ls]);
                index=ls;
            }
        }
        if(st==index) break;
    }
}
int MinHeap::pop()
{
    if(!size) return -1;
    int res=data[1];
    data[1]=data[size--];
    down(1);
    return res;
}
void MinHeap::buildHeap(int *m_data,int k)
{
    size=k;
    for(int i=1;i<=k;i++)
    data[i]=m_data[i];
    for(int i=size/2;i>0;i--)
    down(i);
}
int a[1050];
int main()
{
   int n,m;
   MinHeap heap(1050);
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   cin>>a[i];
   heap.buildHeap(a,n);
   while(m--)
   {
       int x;
       cin>>x;
       int first=1;
       while(x>=1)
       {
           
           if(!first) cout<<" ";
           else first=0;
           cout<<heap.data[x];
            x/=2;
       }
       cout<<endl;
   }
   return 0;
}
