#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{	
	int t;
	cin>>t;
	while(t--)
	{
		int n,cnt=0,a[100]={0};
		cin>>n;
		for(int i=2;i<=n/i;i++)
		{
		if(n%i==0&&i!=a[0]&&i!=a[1])
			{
			n/=i;
			
		
			a[cnt++]=i;
		
			if(cnt==2) break;
				
			}
		}
	if(n>1&&cnt==2&&n!=a[0]&&n!=a[1]) 
	{
		puts("YES");
		 cout<<a[0]<<" "<<a[1]<<" "<<n<<endl;
	}
	
	else 
	puts("NO");
	}
}
