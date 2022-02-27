#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int t = 0, n, temp_odd, temp_even, flag = 0,flag1=0;
    cin >> t;
    while(t--){
        cin >> n;
        temp_odd = temp_even = 0;
        flag = 0;
        for(int i = 1; i <= n; i++){
            int64_t temp;
            cin >> temp;
            if(temp%2 == 0){
                if(temp_even > temp){
                    flag = 1;
                }
                temp_even = temp;
            }
            else{
                if(temp_odd > temp){
                    flag = 1;
                }
                temp_odd = temp;
            }
        }
        if(flag == 1){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
}