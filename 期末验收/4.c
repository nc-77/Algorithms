#include<stdio.h>
#include<string.h>
#include<time.h>
int pos[1500]; // 停车位
int n;
int vis[10500]; //来过车的信息
typedef struct car
{
    int A_Time;
    int D_Time;
    int stat; //停在哪个车位 
}Car;
typedef struct Que
{
    int q[10500];
    int head,tail,size;
}Que;

 Que que;
Car car[10500];  

int check_empty()
{
    for(int i=1;i<=n;i++){
        if(pos[i]==0)
            return i;
    }
    return 0;
}

int main()
{
    int first=1;
   scanf("%d",&n);
   getchar();
    char op;
   int car_id,Time;
       
   while(1){      
        scanf("%c %d %d",&op,&car_id,&Time);
        
       if(op=='E') break;
       if(op=='D'){
           /* 车驶离的时候先判断原来是否在停车场 */
           if(!vis[car_id]){
               printf("the car not in park\n");
               continue;
           }
           /* 驶离操作 */
           int pos_id=car[car_id].stat;
           car[car_id].D_Time=Time;
           pos[pos_id]=0;
           vis[car_id]=0;
           printf("car#%d out,parking time %d\n",car_id,Time-car[car_id].A_Time);
           /* 调整停车场次序,将后面的车全部往前移一位*/
           
           for(int i=pos_id;i<=n;i++){
               if(pos[i+1]) {
                   car[pos[i+1]].stat=i;
                   pos[i]=pos[i+1];
               }
               else{
                   pos[i]=0;
                   break;
               }
           }
           
           /* 有新空位让队列首停车 */
           if(que.size>0){
               que.size--;
               /* top取出队列首 */
               int top=que.q[que.head++];
               int new_pos_id=check_empty();
                vis[top]=1;
                pos[new_pos_id]=top;
                car[top].A_Time=Time;
                car[top].stat=new_pos_id;
                printf("car#%d in parking space #%d\n",top,new_pos_id);
           }
       }
        else if(op=='A'){
            
            int pos_id=check_empty();
            if(pos_id){
                /* 有空位 */
                pos[pos_id]=car_id;
                car[car_id].A_Time=Time;
                car[car_id].stat=pos_id;
                vis[car_id]=1;
                printf("car#%d in parking space #%d\n",car_id,pos_id);
            }
            else{
                /* 需等待 */
                que.q[que.tail++]=car_id;
                que.size++;
                printf("car#%d waiting\n",car_id);
            }
        }
   }
   
   return 0;
}
