#include<bits/stdc++.h>
using namespace std;
int t,n,a[110],b[110];
char s[110];
int main()
{
	int i;
	scanf("%d",&t);
	while(t--)
	  {
       scanf("%s",&s);
       n=strlen(s);
       for(i=1;i<=n;i++)
         a[i]=a[i-1]+(s[i-1]=='x');
       b[n+1]=0;
       for(i=n;i>0;i--)
         b[i]=b[i+1]+(s[i-1]=='l');
       int ans2=n;
       for(i=1;i<=n;i++)
       {
            ans2=min(ans2,(max(0,a[i-1]-2)+max(0,b[i+1]-1)));
       }
        printf("%d\n",ans2);
      }
	return 0;
}
