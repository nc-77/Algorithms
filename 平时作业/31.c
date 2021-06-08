#include<stdio.h>
int a[100000+10];
void swap(int x,int y){
    int temp=a[x];
    a[x]=a[y];
    a[y]=temp;
}
int main()
{
   int n,k;
   scanf("%d %d",&n,&k);
   for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<k;i++){
        
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1]){
                swap(j+1,j);
            }
        }
       
    }
    printf("%d",a[0]);
    for(int i=1;i<n;i++){
        printf(" %d",a[i]);
    }
   return 0;
}
