#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int t = 0;
    cin >> t;
    for(int a = 0; a < t; a++){
        int n,x;
        long long y;
        cin>>n>>x>>y;
        int sum = 0,temp;
        sum = x;
        for(int i=0;i<=n-1;i++){
            cin>>temp;
            sum += temp;
            sum &=1;
        }
        //cout<<sum<<' '<<(y)<<' '<<(y%2)<<endl;
        if((sum % 2)==(y%2)){
            cout<<"Alice"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
    }
    return 0;
}