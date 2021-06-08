#include<bits/stdc++.h> 
#define ll long long
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
char s[100000+10];
int main()
{
	ll n;
	int l=0,r=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
//		if(s[i]=='L') l++;
//		else r++;
	}
	cout<<n+1<<endl;
}
