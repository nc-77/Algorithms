#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;

const int N = 1000050;
 
int to[N], siz[N], n, vis[N], ins[N], sta[N];
int dfs(int x){
    if(siz[x]) return siz[x];
    return siz[x] = 1 + dfs(to[x]);
}
int main()
{	freopen("in.txt","r",stdin);
    int i, j, k, h;
    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%d", &to[i]);
    for(i = 1; i <= n; i ++){
        if(vis[i] == 0){
            j = i;
            while(vis[j] == 0){
                sta[++ sta[0]] = j;
                vis[j] = ins[j] = 1;
                j = to[j];
            }
            debug(i);
            debug(j); 
            if(ins[j]){
                k = j, h = 0;
                do{
                    k = to[k];
                    h ++;
                }while(k != j);
                do{
                	siz[k] = h;
                    k = to[k];
                   
                }while(k != j);
            }
            //else cout<<"here"<<endl;
            while(sta[0]){
                ins[sta[sta[0]]] = 0;
                sta[0] --;
            }
        }
    }
    for(i = 1, h = 0; i <= n; i ++)
        h = max(h, dfs(i));
    printf("%d", h);
     
    return 0;
}

