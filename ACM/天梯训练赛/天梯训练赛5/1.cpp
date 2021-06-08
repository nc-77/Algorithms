#include<bits/stdc++.h>
using namespace std;
int mp[105][105],a[105][105];
int main()
{	int maxx=0;
	int n,num=1,m,flag=-1;
	cin>>n;

	for(int i=1;i<=n;i++){
		cin>>m;
		maxx=max(maxx,m);
		for(int j=1;j<=10*m;j++){
			mp[i][j]=1;
		}
	}
 
	for(int i=1;i<=10*maxx;i++){
		for(int j=1;j<=n;j++){
			if(mp[j][i]){  
				if(flag!=j){
					a[j][i]=num++;
					flag=j;
				}
				else{
					num+=1;
					a[j][i]=num++;
					flag=j;
				}
			}
		}
	}
	//cout<<maxx<<" "<<a[1][10]<<endl;
	for(int i=1;i<=n;i++){
		cout<<"#"<<i<<endl;
		for(int j=1;j<=10*maxx;j++){
			if(a[i][j])
			{
				if(j%10!=0) cout<<a[i][j]<<" ";
				else cout<<a[i][j]<<endl;
			}
		
		}
	}

}

