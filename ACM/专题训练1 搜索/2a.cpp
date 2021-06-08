#include <bits/stdc++.h>
using namespace std;
#define N 1005
struct node
{
    int x,y,count;
};
int a[N][N];
int mark[N][N];
int x1,y1,x2,y2;
int dis[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int ch;

void BFS(int x,int y)
{
    queue<node> q;
    node s1,s2;
    s1.x=x;
    s1.y=y;
    s1.count=0;
    q.push(s1);
    int i;
    memset(mark,0,sizeof(mark));
    mark[x][y]=1; 
    while(!q.empty())
    {
        s1=q.front();
        q.pop();
        if(s1.count>3)
		{
            printf("NO\n");
			return;
		}
        for(i=0;i<4;i++)
        {
            
            s2.x=s1.x+dis[i][0];
            s2.y=s1.y+dis[i][1];
            while(a[s2.x][s2.y]==0&&mark[s2.x][s2.y]==0)
            {	
                	
                    mark[s2.x][s2.y]=1;
					s2.count=s1.count+1;
                    q.push(s2);
                    //cout<<s2.x<<" "<<s2.y<<" "<<s2.count<<endl;
                    if(s2.x==x2 && s2.y==y2)
                    {
                        if(s2.count<=3)
                            printf("YES\n");
                        else
                            printf("NO\n");
						return;
                    }
                
                s2.x+=dis[i][0];
                s2.y+=dis[i][1];
            }
        }
    }
}

int main()
{
    
    int t,n,m,i,j;
    while(cin>>n>>m&&!(n==0&&m==0))
    {
        memset(a,-1,sizeof(a));
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			int temp=a[x2][y2];
			a[x2][y2]=0;
            if(a[x1][y1]==temp && a[x1][y1]!=0)
            {
					ch=a[x1][y1];
                    BFS(x1,y1);
              
            }
            else
                printf("NO\n");
			a[x2][y2]=temp;
        }
    }
    return 0;
} 
