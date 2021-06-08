#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;

struct Window
{
    int end_time;
    int people;
}window[11];
struct people
{
    int st_time;
    int need_time;
    int wait_time;
    int finish_time;
    int index;
}peo[1010];
int windows_empty(int k,int Time){
    int wait_min=0x3f3f3f3f,ret;
    for(int i=0;i<k;i++){
        if(window[i].end_time<=Time)
         return i;
         else {
             if(wait_min>window[i].end_time-Time){
                 wait_min=window[i].end_time-Time;
                 ret=i;
             }
            
         }
    }
    return -(1+ret);
}

int main()
{
   queue<people>que;
   int n,k;
   
   cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>peo[i].st_time>>peo[i].need_time;
        peo[i].need_time=min(60,peo[i].need_time);
        peo[i].index=i;
        que.push(peo[i]);
    }
    cin>>k;
    while(!que.empty()){
        people cur=que.front();
        
       
        int i=cur.index;
        int win=windows_empty(k,cur.st_time);
        // cout<<"Time= "<<Time<<"Win= "<<win<<endl;
        if(win>=0){
            peo[i].wait_time=0;
            peo[i].finish_time=peo[i].st_time+peo[i].need_time;
            window[win].people++;
            window[win].end_time=peo[i].finish_time;
        }
        else{
            
            win=-win-1;
           
            peo[i].wait_time=window[win].end_time-peo[i].st_time;
            

            peo[i].finish_time=window[win].end_time+peo[i].need_time;
            window[win].people++;
            window[win].end_time=peo[i].finish_time;
        }
         que.pop();
    }

    int wait_longest=0,wait_last=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=peo[i].wait_time;
        wait_longest=max(wait_longest,peo[i].wait_time);
        wait_last=max(wait_last,peo[i].finish_time);
        //cout<<i<<" wait_time="<<peo[i].wait_time<<" finish_time="<<peo[i].finish_time<<endl;
    }
    printf("%.1lf %d %d\n",(sum*1.0)/(n*1.0),wait_longest,wait_last);
    for(int i=0;i<k;i++){
        if(i)cout<<" ";
        cout<<window[i].people;
    }
   return 0;
}
