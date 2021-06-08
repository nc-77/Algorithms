#include<stdio.h>

int n;
int a[105],b[105];
void swap(int *x,int *y){
    int temp=*y;
    *y=*x;
    *x=temp;
}
int judge(int *a,int *b)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}
void show(int *a){
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
        if(i!=n-1) printf(" ");
    }
    printf("\n");
}
int insert_sort()
{
    int t[105];
    int A[105];
    for(int i=0;i<n;i++){
        A[i]=a[i];
    }
    for(int i=1;i<n;i++)
    {
        int pos;
        int x=A[i];
        static  int flag=0;
        for(pos=i-1;pos>=0&&A[pos]>x;pos--){
            A[pos+1]=A[pos];
        }
        A[pos+1]=x;
        if(flag){
            puts("Insertion Sort");
            show(A);
            return 1;
        }
        if(judge(A,b)) {
            flag=1;
        }
    }
    return 0;
}
void down(int root,int n)
{
    
    while(1)
    {
        int st=root;
        int ls=root*2+1;
        int rs=ls+1;
        if(rs<n){ //有右儿子
            int ms=a[ls]>a[rs]?ls:rs;
            if(a[root]<a[ms]) {
                swap(&a[root],&a[ms]);
                root=ms;
            }
        }
        else if(ls<n){
            if(a[root]<a[ls]) {
                swap(&a[root],&a[ls]);
                root=ls;
            }
        }
        if(st==root) break;
    }
}
void Heap_sort()
{
    // 建立最大堆
    for(int i=n/2-1;i>=0;i--)
        down(i,n);
    for(int i=n-1;i>=0;i--)
    {
        static int flag=0;
        swap(&a[i],&a[0]);
        down(0,i);
        if(flag){
            puts("Heap Sort");
            show(a);
            return;
        }
        if(judge(a,b)){
            flag=1;
        }
        //show();
    }
}
int main()
{
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    if(!insert_sort()){
         Heap_sort();
    }
   return 0;
}
