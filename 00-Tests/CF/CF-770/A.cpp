#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n = 0;
    cin >> n;
    for(int a = 0; a < n; a++){
        int l,k;
        char temp[120];
        bool rev = 1;
        cin >> l >> k;//reverse - 1/unreverse
        cin >> temp;
        for(int i = 0, j = l-1; i <= j; i++, j--){
            if(temp[i]!=temp[j]){
                rev = 0;
                break;
            }
            else{
                rev = 1;
                continue;
            }
        }
        //cout << temp <<' '<< rev<<endl;
        if(k == 0){
            cout<<"1"<<endl;
            continue;
        }
        else{
            if (rev == 1){
                cout<<"1"<<endl;
            }
            else if(rev == 0){
                cout<<"2"<<endl;
            }
        }
    }
    return 0;
}