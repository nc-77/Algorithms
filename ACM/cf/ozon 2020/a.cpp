#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=120+10;
int a[maxn],b[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
	cin>>t;
	while(t--)
	{	set0(a),set0(b);
		int n;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		cout<<a[0];
		for(int i=1;i<n;i++) cout<<" "<<a[i];
		cout<<endl;
		cout<<b[0];
		for(int i=1;i<n;i++) cout<<" "<<b[i];
		cout<<endl;
	} 
}

