#include<bits/stdc++.h>
using namespace std;
char ss[5050];
int main()
{	
    //freopen("in.txt","r",stdin);
    int t;
	cin>>t;
	while(t--)
	{	int cnt=0,k=0;
			int n;
			cin>>n;
			string s;
			cin>>s;
			char mi='z';
			int ans=0;
		string tt="~";
		
		for(int i=0;i<n;i++)
		{
			mi=min(mi,s[i]);
			ss[i+1]=s[i];
		}
		for(int i=0;i<n;i++)
			{
				if(s[i]==mi)
				{	string s1=s.substr(i);
					string s2=s.substr(0,i);
					string s3=s1;
					if((n-(i+1))%2==0) 
					{
						reverse(s2.begin(),s2.end());
						s3+=s2;
					}
					else s3=s1+s2;
				if(s3<tt)
				tt=s3,ans=i+1;
				k++;
			}
		}
		cnt++;
		for(int i=1;i<=n-ans+1;i++)
		{
			reverse(ss+i,ss+i+ans);
		}
		for(int i=1;i<=n;i++) cout<<ss[i];
		cout<<endl;
		cout<<ans<<endl;
	 } 
    
}

