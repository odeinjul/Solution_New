#include <iostream>
using namespace std;
int main(){
    int t, n, a, b, flag;
    cin >> t;
    while(t--){
        cin >> n;
        b = 0;
        a = 0;
        flag = 0;
        if(n == 1){
            cin >> a;
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0; i < n;i ++){
            cin >> a;
            if(a < b){
                flag = 1;
            }
            b = a;
        }
        if(flag == 1)
            cout << "YES" << endl;
        else if(flag == 0)
            cout << "NO" << endl; 
        
    }
    return 0;
}