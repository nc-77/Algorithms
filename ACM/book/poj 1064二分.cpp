#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
using namespace std;
int n,k;
double len[10100];
bool judge(double x)
{
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=(int)(len[i]/x);
    }
    return cnt>=k;
}

int main()
{	double MAX=-1;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&len[i]);
		MAX=max(len[i],MAX);
	}
	 double lb=0,ub=MAX,mid;
    while(ub-lb<1e-7)
	{
         mid=(lb+ub)/2;
        if(judge(mid)){
            lb=mid;
        }
        else{
            ub=mid;
        }
    }
	printf("%.2f",floor(mid*100)/100);
} 
