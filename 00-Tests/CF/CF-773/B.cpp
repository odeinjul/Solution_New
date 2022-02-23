#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int t = 0, n, power[300010], cnt;
    cin >> t;
    while(t--){
        cnt = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> power[i];
        }
        sort(power + 1, power + n + 1);
        for(int i = 1; i <= n; i++){
            if(power[i] != power[i - 1]){
                cnt++; //cnt stands for the number of different power
            }
        }
        for(int k = 1; k <= n; k++){
            if(k<=cnt){
                cout << cnt << ' ';
            }
            else{
                cout << k << ' ';
            }
        }
        cout <<endl;
    }
    return 0;
}
