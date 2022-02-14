#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int t = 0, n, temp[100010],flag=0,flag1=0;
    cin >> t;
    while(t--){
        cin >> n;
        //cout<<t<<endl;
        flag = 0; flag1= 0;
        temp[0]=0;
        for(int i = 1; i <= n; i++){
            cin >> temp[i];
            if(temp[i]<temp[i-1]){
                flag = 1;
                if((temp[i]+temp[i-1])%2==0){
                    flag1=1;
                    //cout<<i<<' '<<temp[i]<<' '<<temp[i-1]<<endl;
                }
            }
        }
        if(flag == 0){
            cout<<"YES"<<endl;
            continue;
        }
        else if(flag1 == 1){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(temp[i] > temp[j] && (temp[i]+temp[j])%2 == 0){
                    flag1 = 1;
                    break;
                }
            }
            if(flag1==1)
                break;
        }
        if(flag1 == 1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}