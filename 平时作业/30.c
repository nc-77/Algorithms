#include<stdio.h>
int a[100000+10];
void swap(int x,int y){
    int temp=a[x];
    a[x]=a[y];
    a[y]=temp;
}
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        int k=i;
        for(int j=i;j<n;j++)
        {
            if(a[j]>a[k]){
                k=j;
            }
        }
        swap(k,i);
    }
    printf("%d",a[0]);
    for(int i=1;i<n;i++){
        printf(" %d",a[i]);
    }
   return 0;
}
