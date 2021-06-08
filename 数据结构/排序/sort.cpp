#include<iostream>
#include<cstring>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
class MyArr
{
    private:
        int *A;
        int len;
        // merge_sort
        void merge(int L,int R,int Rend);
        // Heap_sort
        void down(int root,int n);
    public:
        MyArr(int *p,int n):A(p),len(n){}
        ~MyArr(){}
        void show();
        void merge_sort(int L,int R);
        void Heap_sort();
        void InsertionSort();
        void QuickSort(int Left,int Right);
};
const int maxn=1e5+10;
int a[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    MyArr t(a,n);
    t.Heap_sort();
    t.show();
   return 0;
}

void MyArr::show()
{
    for(int i=0;i<len;i++){
        cout<<A[i];
        if(i!=len-1){
            cout<<" ";
        }
    }
    cout<<endl;
}
/* merge_sort 封装*/
/* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
void MyArr::merge(int L,int R,int Rend)
{
    int Lend=R-1;
    int tmp=L;
    int st=L;
    int *TmpA=new int[len];
    while(L<=Lend&&R<=Rend)
    {
        if(A[L]<=A[R]) TmpA[tmp++]=A[L++];
        else TmpA[tmp++]=A[R++];
    }
    while(L<=Lend) TmpA[tmp++]=A[L++];
    while(R<=Rend) TmpA[tmp++]=A[R++];
    for(int i=st;i<=Rend;i++)
    A[i]=TmpA[i];
    delete []TmpA;
}
void MyArr::merge_sort(int L,int R)
{
    if(L<R){
        int mid=(L+R)/2;
        merge_sort(L,mid);
        merge_sort(mid+1,R);
        merge(L,mid+1,R);
    }
}
/* Heap_sort封装 */
void MyArr::down(int root,int n)
{
    
    while(1)
    {
        int st=root;
        int ls=root*2+1;
        int rs=ls+1;
        if(rs<n){
            int ms=A[ls]>A[rs]?ls:rs;
            if(A[root]<A[ms]) {
                swap(A[root],A[ms]);
                root=ms;
            }
        }
        else if(ls<n){
            if(A[root]<A[ls]) {
                swap(A[root],A[ls]);
                root=ls;
            }
        }
        if(st==root) break;
    }
}
void MyArr::Heap_sort()
{
    // 建立最大堆
    for(int i=len/2-1;i>=0;i--)
        down(i,len);
    for(int i=len-1;i>=0;i--)
    {
        swap(a[i],a[0]);
        down(0,i);
        //show();
    }
}
/* 插入排序 */
void MyArr::InsertionSort()
{ 
     int  i;
     for ( int P=1; P<len; P++ ) {
         int Tmp = A[P]; 
         for ( i=P; i>0 && A[i-1]>Tmp; i-- )
             A[i] = A[i-1]; 
         A[i] = Tmp; 
     }
}

/* 快速排序 */
void MyArr::QuickSort(int Left,int Right)
{
    
}