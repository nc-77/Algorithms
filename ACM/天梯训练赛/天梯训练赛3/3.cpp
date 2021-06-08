#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int maxn=1500;
struct book{
    int H;
    int M;
};
int main(){
    int n,num,hh,mm,state[maxn];
    char a,b;
    map <int,book> mp;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        int mx,sm = 0,cnt = 0;
        memset(state,0,sizeof(state));
        while(1){
            scanf("%d %c%d %c%d",&num,&a,&hh,&b,&mm);
            if(num==0) break;
            if(a=='S'){
                state[num] = 1;
                mp[num].H = hh;
                mp[num].M = mm;
            }
            else if(a=='E'&&state[num] == 1){
                cnt++;
                state[num] = 0;
                mx=hh*60+mm-mp[num].H*60-mp[num].M;
                sm+=mx;
            }
        }
        if(!cnt)
            printf("0 0\n");
        else
            printf("%d %d\n",cnt,(int)((sm*1.0/cnt)+0.5));
    }
}

