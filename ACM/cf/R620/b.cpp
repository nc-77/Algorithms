#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;
string s[150];
map<string,int>mp;
int n,m;
int n1[150],h[150];
bool check(string s)
{	string t=s;
	reverse(t.begin(),t.end());
	if(t==s) return true;
	else return false;
}
int main()
{
    //freopen("in.txt","r",stdin);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>s[i];
    	mp[s[i]]=1;
	}
	int c1=0,c2=0;
	int ans=0;
    for(int i=1;i<=n;i++)
    {
    	if(check(s[i]))
    	{
    		h[c2++]=i;
    		
    		
		}
    	else if(mp[s[i]]==1)
    	{	string t=s[i];
    		
    		reverse(t.begin(),t.end());
    		//cout<<s[i]<<endl;
    		if(mp[t]==1) 
			{
				ans+=2*m;
				mp[t]--;
				n1[c1++]=i;
			}
    	
		}
	}
	if(c2) ans+=m;
	cout<<ans<<endl;
	for(int i=0;i<c1;i++)
	{
		cout<<s[n1[i]];
		//cout<<"hre"<<endl;
	}
	if(c2)
	{
		
		cout<<s[h[0]];
	}
	
	for(int i=c1-1;i>=0;i--)
	{
		reverse(s[n1[i]].begin(),s[n1[i]].end());
		cout<<s[n1[i]];
	}
}

