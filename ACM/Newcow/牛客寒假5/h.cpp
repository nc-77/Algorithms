#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
#define PI 3.14159265
using namespace std;
const int LEN = 6;

int Hash(string s,int mod)
{
    int res = 0;
    for (int i = 0; i < LEN; i++)
    {
        res = (res * 26 + s[i]) % mod; 
    }
    return res;
}
int Hashc(int *a,int mod)
{
    int res = 0;
    for (int i = 0; i < LEN; i++)
    {
        res = (res * 26 + a[i]) % mod; 
    }
    return res;
}
int a[10],ans[10];
int main()
{
	string s;
	int m;
	while(cin>>s)
	{	cin>>m;
		set0(ans);
		set0(a);
		for(int i=0;i<s.size();i++)
		s[i]=s[i]-'a';
		a[5]=m%26;
		a[4]=m/26%26;
		a[3]=m/26/26%26;
		a[2]=m/26/26/26%26;
		a[1]=m/26/26/26/26%26;
		a[0]=m/26/26/26/26/26%26;
		for(int i=5;i>=1;i--)
		{
			ans[i]+=s[i]+a[i];
			//debug(ans[i]);
			if(ans[i]>=26) 
			ans[i-1]++;
			ans[i]=ans[i]%26;
		}
		//cout<<Hash(s,m)<<" "<<Hashc(ans,m)<<endl;
		ans[0]+=s[0]+a[0];
		if(ans[0]>=26) puts("-1");
		
		else 
		{
			for(int i=0;i<6;i++)
			cout<<char(ans[i]+'a');
			cout<<endl;
		}
	}
	
}
