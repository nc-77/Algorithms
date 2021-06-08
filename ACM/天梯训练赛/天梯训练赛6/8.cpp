#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{	double h;
		char sx;
		cin>>sx>>h;
		if(sx=='M') 
		printf("%.2f\n",h*1.0/1.09);
		else 
		printf("%.2f\n",h*1.09);
	}
}
