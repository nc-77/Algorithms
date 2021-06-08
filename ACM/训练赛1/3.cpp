#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e7+10;
char  a[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    ll k;
    cin>>k;
    if(k>=0&&k<=25)
    {
    	cout<<'a';
    	cout<<(char)('a'+k);
    	return 0;
	}
    ll x=k/25;
    if(k%25==0&&k!=0) x--;
    x++;
    for(int i=1;i<=x+1;i++)
    {
    	if(i%2==1) a[i]='a';
    	else a[i]='z';
	}
	ll ans=x*25-50;
	if((k-ans)%2==0)a[2]='a'+(k-ans)/2;
	else 
	{	if(x%2==1)
		{
			a[x+1]='y';
			a[2]='a'+(k-ans-1)/2+1;
		}
		else
		{
			a[x+1]='b';
			
			a[2]='a'+(k-ans-1)/2+1;
		}
	}
	for(int i=1;i<=x+1;i++)
	cout<<a[i];
//	if(x%2==1) cout<<(char)('a'+ans)<<endl;
//	else cout<<(char)('z'-ans)<<endl;
	
    
}

