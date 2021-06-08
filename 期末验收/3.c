#include<stdio.h>
#include<stdlib.h>
#define maxn 400010
int a[maxn],b[maxn],c[maxn],d[maxn];
int n,m;
int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
/* 二分查找 b数组中是否有x */
int find(int x)
{
    int l=0,r=m;
    int mid;
    while(l<r){
        mid = l + r >> 1;
        if (x<b[mid]) r = mid;
        else if(x==b[mid]) return 1;
        else l = mid + 1;
    }
    return 0;
}
int main()
{
   
   scanf("%d %d",&n,&m);
   for(int i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
       c[i]=a[i];
   }
   for(int i=0;i<m;i++)
   {
       scanf("%d",&b[i]);
       c[n+i]=b[i];
   }
   /* 将a,b,c三个数组升序排序 */
    qsort(a,n,sizeof(int),comp);
    qsort(b,m,sizeof(int),comp);
    qsort(c,m+n,sizeof(int),comp);
    /* 求交集 */
    int same=0;
    for(int i=0;i<n;i++){
        if(find(a[i])){
            d[same++]=a[i];
        }
    }
    printf("%d",same);
    for(int i=0;i<same;i++){
         printf(" %d",d[i]);
    }
    printf("\n");
    printf("%d",m+n-same);
    for(int i=0;i<m+n;i++){
        /* 去重 */
        if(i&&c[i]==c[i-1]) continue;
       printf(" %d",c[i]);
    }
   return 0;
}
