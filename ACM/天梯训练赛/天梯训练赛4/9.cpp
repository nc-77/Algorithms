#include<bits/stdc++.h>
using namespace std;
int tvis[10000+10],num,jl[10000+10],ans1[10000+10],ans2[10000+10];
map<int,int>mp;
bool judge(int x)
{	while(1)
	{
		if(x==1) return true;
		int a=x/10000;
	int b=x/1000%10;
	int c=x/100%10;
	int d=x/10%10;
	int e=x%10;
	x=a*a+b*b+c*c+d*d+e*e;
	if(mp[x]) return false;
	else 
	{
		jl[num++]=x;
		mp[x]=1;
	}
	}	
}
bool p(int n)
{
    if(n<2) return false;
    for(int i=2;i<=n/i;i++)
    if(n%i==0) return false;
    return true;
}
int main()
{
	int a,b,flag=0,cnt=0;
	cin>>a>>b;
	for(int i=b;i>=a;i--)
	{	num=0;
		if(tvis[i]) continue;
		if(judge(i))
		{	flag=1;
			for(int i=0;i<num;i++)
			tvis[jl[i]]=1;
		
			if(p(i)) num=2*num;
			//cout<<num<<endl;
			ans1[cnt]=i;
			ans2[cnt]=num;
			cnt++;
			mp.clear();
			
			memset(jl,0,sizeof(jl));
		}
		
	}
	if(!flag) cout<<"SAD"<<endl;
	else
	{
		for(int i=cnt-1;i>=0;i--)
		cout<<ans1[i]<<" "<<ans2[i]<<endl;
	}
}
