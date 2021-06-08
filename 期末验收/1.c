#include<stdio.h>
int a[3010];
int main()
{
   int n,p;
   scanf("%d%d",&n,&p);
   int alive=n;// 刚开始有n个人在圈内
   int now=1;
   for(int i=1;i<=n;i++) a[i]=1;
   int first=1;
   while(alive>0){
       int cnt=0;
       for(int i=now;;i++){
           int index=(i+n-1)%n+1;
           if(!a[index]) continue;
           cnt++;
           if(cnt==p){
               a[index]=0;
               /* 处理行尾空格问题 */
               if(first){
                   printf("%d",index);
                   first=0;
               }
               else printf(" %d",index);
               alive--;
               /* 从下一位开始 */
               now=i+1;
               break;
           }
       }
   }
   return 0;
}
