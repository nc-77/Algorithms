#include<bits/stdc++.h>
using namespace std;
int main()
{	int d[11]={0},cnt=0;
	string s;
	cin>>s;
	for(int i=0;i<11;i++)
	{
		d[s[i]-'0']++;
	}
	    printf("int[] arr = new int[]{");
	    for(int i=9;i>=0;i--)
	    {
	    	if(d[i])
	    	{	d[i]=cnt;
				if(cnt==0)
	    		printf("%d",i);
	    		else
	    		printf(",%d",i);
	    		cnt++;
	    	}
		}
	printf("};\n");
    printf("int[] index = new int[]{");
    for(int i=0;i<11;i++)
    {
    	if(i==0) printf("%d",d[s[i]-'0']);
    	else printf(",%d",d[s[i]-'0']);
	}
	printf("};\n");
}
