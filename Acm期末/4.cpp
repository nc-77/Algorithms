#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
const int maxn=1e5+10;
int a[maxn];
int sum[maxn];
int main()
{
    int n,m;
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        memset(sum,0,sizeof(sum));
        
        for(int i=1;i<=n;i++){
            sum[i]=a[i]+sum[i-1];
        }
        while(m--){
            int a,b;
            cin>>a>>b;
            if(a>b) swap(a,b);


            
            cout<<sum[b]-sum[a-1]<<endl;
        }
    }
   return 0;
}
