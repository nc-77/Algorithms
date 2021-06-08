#include<stdio.h>
#include<string.h>
#define maxn 150
char string[maxn];
int main()
{
   scanf("%s",string);
   int n=strlen(string);
   for(int i=0;i<n;i++){
       if(string[i]=='B'){
           printf("tsaedsae");
       }
       else if(string[i]=='A'){
           printf("sae");
       }
       else if(string[i]=='('){
           char res[maxn];
           int size=0;
           while(string[i]!=')'){
               res[size++]=string[i];
               i++;
           }
           for(int j=size-1;j>1;j--){
               printf("%c%c",res[1],res[j]);
           }
           printf("%c",res[1]);
       }
   }
   return 0;
}
