#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[100][100];
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
int fun(int x)
{
    if(x==9) return 8;
    else return x+1; 
}
int main()
{   ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {    string s[12];
       for(int i=1;i<10;i++) 
       {
           cin>>s[i];}
       for(int i=1;i<10;i++)
       {
           for(int j=1;j<10;j++)
           a[i][j]=s[i][j-1]-'0';
       }
        a[1][1]=fun(a[1][1]);
        a[2][4]=fun(a[2][4]);
        a[3][7]=fun(a[3][7]);
        a[4][2]=fun(a[4][2]);
        a[5][5]=fun(a[5][5]);
        a[6][8]=fun(a[6][8]);
        a[7][3]=fun(a[7][3]);
        a[8][6]=fun(a[8][6]);
        a[9][9]=fun(a[9][9]);
        for(int i=1;i<10;i++)
        {
            for(int j=1;j<10;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
        }
       
   }
   //system("pause");
   return 0;
}
