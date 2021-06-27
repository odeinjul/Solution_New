//高精度乘单精度
#include <iostream>
#include <cstring>
using namespace std;
int n,num[1000000]={1};
int main(){
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        int l=1,temp;
        for(int j=2;j<=a;j++){
            temp = 0;
            for(int k=0;k<l;k++){
                num[k] = num[k]*j+temp;
                temp = num[k] / 10;
                num[k] %= 10;
            }
            while(temp>0){
                num[l]=temp%10;
                l++;
                temp/=10;
            }
        }
        int sum=0;
        for(int i=0;i<l;i++){
            if(num[i] == b)
                sum++;
        }
        cout<<sum<<endl;
        memset(num,0,sizeof(num));
        num[0]=1;
    }
    return 0;
}