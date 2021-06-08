#include<stdio.h>
#include<stdlib.h>
int vec[200000+10];
int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
   int n;
    int len=0;
   scanf("%d",&n);
   for(int i=0;i<n+n;i++){
       int x;
       scanf("%d",&x);
       vec[len++]=x;
   }
   
   qsort(vec,len,sizeof(int),comp);
   printf("%d",vec[(2*n+1)/2-1]);
   return 0;
}
