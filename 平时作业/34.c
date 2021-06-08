#include<stdio.h>
int box[1050];
int n;
struct Car
{
    int val;
    int where;
}car[1050];
void work(int id){
    for(int i=0;i<n;i++){
        if(box[i]>=car[id].val){
            box[i]-=car[id].val;
            car[id].where=i+1;
            return;
        }
    }
}
int main()
{
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        box[i]=100;
    }
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&car[i].val);
        work(i);
    }
    for(int i=0;i<n;i++){
        printf("%d %d\n",car[i].val,car[i].where);
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(box[i]!=100) cnt++;
    }
    printf("%d",cnt);
   return 0;
}
