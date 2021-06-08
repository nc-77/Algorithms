#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
ll a[100000+10];
int main()
{
	int t;
	ll cursum,maxsum; 
	cin>>t;
	while(t--)
	{	ll sum=0;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		maxsum=-INF,cursum=0;
		int temp=0,start=0,end;
		for(int i=0;i<n;i++)
		{
			
			if(cursum<=0)
			{
				cursum=a[i];
				temp=i;
			}
			
			else
				cursum+=a[i];
			
			 if(cursum>maxsum)
			{
				
				maxsum=cursum;
				//cout<<temp+1<<" "<<i+1<<endl;
				start=temp+1;
				end=i+1;
			}
			//cout<<start<<" "<<end<<endl;
		}
		
		//cout<<maxsum<<endl;
		if(maxsum==sum&&start==1&&end==n)
		puts("YES");
		else if(maxsum>=sum)
		puts("NO");
		else if(maxsum<sum)
		puts("YES");


	}
}
