#include <iostream>
#include <cstring>
using namespace std;
int temp[110],an[110];
int helper(int l, int r, int l0, int r0, int index);
int main(){
    int t = 0, n = 0, l = 0, r = 0, sum = 0;
    cin >> t;
    while(t --){
        sum = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> temp[i];
            if(temp[i])
                an[i] = 1;
            else   
                an[i] = 2;
        }
        for(int l = 0; l < n; l++){
            for(int r = n-1; r >= l; r--){
                //[l..r]
                int t0 = 0;
                for(int i = l; i <= r; i++){
                    t0 += an[i];
                }
                //cout<<"t0 "<<t0<<endl;
                sum += t0;
            }
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}
