#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stu
{
    char id[20];
    int score;
    int number;
    int kaodian_pm;
    int pm;
}stu[30000+10];
int peo[110][110];
int comp(const void *c, const void *d)
{
    struct Stu *a = (struct Stu *)c;
    struct Stu *b = (struct Stu *)d;
    if(b->score==a->score){
        if(strcmp(a->id,b->id)>0){
            return 1;
        }
        else return -1;
    }
    else return b->score-a->score;
}
int main()
{
   int n;
   int sum=0;
   scanf("%d",&n);
   for(int k=0;k<n;k++)
   {
       int number;
       scanf("%d",&number);
       for(int i=0;i<number;i++){
           scanf("%s",stu[sum].id);
           scanf("%d",&stu[sum].score);
           //printf("%s\n",stu[i].id);
           stu[sum].number=k+1;
           stu[sum].kaodian_pm=1;
           stu[sum].pm=1;
           peo[k+1][stu[sum].score]++;
           sum++;
       } 
   }
   for(int i=0;i<sum;i++){
       int number=stu[i].number;
       for(int j=stu[i].score+1;j<=100;j++)
       stu[i].kaodian_pm+=peo[number][j];
   }
   for(int i=0;i<sum;i++){
       for(int j=1;j<=n;j++)
       {
           for(int k=stu[i].score+1;k<=100;k++)
           stu[i].pm+=peo[j][k];
       }
   }
   //printf("sum=%d\n",sum);
//    printf("\n");
//    for(int i=0;i<sum;i++){
//        printf("%s %d %d %d\n",stu[i].id,stu[i].pm,stu[i].number,stu[i].kaodian_pm);
//    }
//    printf("\n");
   qsort(stu,sum,sizeof(struct Stu),comp);
   printf("%d\n",sum);
   for(int i=0;i<sum;i++){
       printf("%s %d %d %d\n",stu[i].id,stu[i].pm,stu[i].number,stu[i].kaodian_pm);
   }
   return 0;
}
