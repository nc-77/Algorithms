#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Stu
{
    char id[100];
    char name[100];
    int score;
}Stu;
Stu stu[100000+10];
int cmp3(const void *c, const void *d)
{
    struct Stu *a = (struct Stu *)c;
    struct Stu *b = (struct Stu *)d;
    if(b->score==a->score){
        if(strcmp(a->id,b->id)>0){
            return 1;
        }
        else return -1;
    }
    else return a->score-b->score;
}
int cmp2(const void *c, const void *d)
{
    struct Stu *a = (struct Stu *)c;
    struct Stu *b = (struct Stu *)d;
    
        if(strcmp(a->name,b->name)>0){
            return 1;
        }
        else if(strcmp(a->name,b->name)==0){
            if(strcmp(a->id,b->id)>0){
            return 1;
        }
        else return -1;
        }
        else return -1;
    
}
int cmp1(const void *c, const void *d)
{
    struct Stu *a = (struct Stu *)c;
    struct Stu *b = (struct Stu *)d;
    
        if(strcmp(a->id,b->id)>0){
            return 1;
        }
        else return -1;
    
}
int main()
{
   int n,op;
   scanf("%d %d",&n,&op);
   for(int i=0;i<n;i++){
       scanf("%s %s %d",stu[i].id,stu[i].name,&stu[i].score);
   }
   if(op==1){
       qsort(stu,n,sizeof(stu[0]),cmp1);
   }
   else if(op==2){
       qsort(stu,n,sizeof(stu[0]),cmp2);
   }
   else{
       qsort(stu,n,sizeof(stu[0]),cmp3);
   }
   for(int i=0;i<n;i++){
       printf("%s %s %d\n",stu[i].id,stu[i].name,stu[i].score);
   }
   return 0;
}
