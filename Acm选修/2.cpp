#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
struct Stu
{
    double score;
    int age;
    string name;
}stu[110];
bool cmp(const Stu &a,const Stu &b){
    if(a.score!=b.score){
        return a.score>b.score;
    }
    else{
        if(a.age!=b.age) return a.age<b.age;
        else return a.name<b.name;
    }
}
int main()
{
   int n;
   while(cin>>n)
   {
       for(int i=0;i<n;i++){
       cin>>stu[i].name>>stu[i].age>>stu[i].score;
        }
        sort(stu,stu+n,cmp);
        for(int i=0;i<n;i++){
            cout<<stu[i].name<<" "<<stu[i].age;
            printf(" %.2f\n",stu[i].score);
        }
   }
   

   return 0;
}
