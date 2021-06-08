#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10;
int check[maxn];
int prime[maxn];
int ans[maxn];
int main()
{
	int n,m;
	cin>>n>>m;
  for (int i = 2; i <= n; ++i)
  {
    if (!check[i])
   {
      prime[i] =1;
    }
    for (int j = i+i; j <= n; j += i)
   	{
     check[j] = 1;
   	}
   
 	}
 	prime[1]=1;
 	for(int i=1;i<=n;i++)
 	{	int x=0;
 		int k=sqrt(i);
 		for(int j=1;j<=k;j++)
 		{
 			if(i%j==0)
 			{
 				if(!prime[j])
 				x++;
 				if(j*j!=i&&!prime[i/j])
 				x++;
			 }
 		
 			
		 }
		 //cout<<i<<" "<<x<<endl;
		 ans[x]++;
	 }
	 while(m--)
	 {
	 	int y;
	 	cin>>y;
	 	cout<<ans[y]<<endl;
	 }
}
