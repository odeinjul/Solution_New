#include<cstdio> 
#include<cstring> 
#include<iostream>
#include<algorithm>
using namespace std;
char a[1000100],b[1000100];
int p[1000100];
int main()
{
    scanf("%s%s",a+1,b+1);
    /*for(int i = 0; i <= strlen(a+1); i++){
        cout<<i<<' '<<a[i]<<endl;
    }*/
    int la=strlen(a+1),lb=strlen(b+1);
    p[1]=0;
    int t = p[1];
    for(int i = 2; i <= lb; i++){
        while(t>0 && b[i]!=b[t+1]) t = p[t];
        if(b[i]==b[t+1]) t++;
        p[i]=t;
    }
    t = 0;
    for(int i = 1; i <= la; i++){
        //t = p[i];
        while(t>0 && a[i]!=b[t+1]) t = p[t];
        if(a[i]==b[t+1]) t++;
        if(t==lb){cout<<i-lb+1<<endl;}
    }
    for(int i=1;i<lb;i++)
        cout<<p[i]<<' ';
    cout<<p[lb]<<endl;
    return 0;
}