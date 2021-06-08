#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int main()
{	int num=0;
	int n;
	cin>>n;
	int t=n;
	while(n--)
	{	int sum=0;
		int flag=0;
		string s;
		cin>>s;
		for(int i=0;i<s.size()-1;i++)
		{
			if(s[i]>'9'||s[i]<'0')
			{
				flag=1;
				cout<<s<<endl;
				break;
			}
			sum+=(s[i]-'0')*a[i];
		}
		if(flag) continue;
		sum=sum%11;
		if(sum==0) sum=1;
		else if(sum==1) sum=0;
		else if(sum==2) 
		{
			sum=(char)sum;
			sum='X';
		}
		else if(sum==3) sum=9;
		else if(sum==4) sum=8;
		else if(sum==5) sum=7;
		else if(sum==6) sum=6;
		else if(sum==7) sum=5;
		else if(sum==8) sum=4;
		else if(sum==9) sum=3;
		else if(sum==10) sum=2;
		
		
		if((int)sum==(int)(s[17]-'0')) 
		{	//cout<<"here"<<endl;
			num++;
		 } 
		 else cout<<s<<endl;
		 if(num==t) cout<<"All passed"<<endl;
	}
}
