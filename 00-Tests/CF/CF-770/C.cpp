#include <iostream>
#include <cstring>
using namespace std;
int ans[3][600];
void solve(int n, int k);
int main(){
    int t = 0, n, k;
    cin >> t;
    for(int a = 0; a < t; a++){
        cin >> n >> k;
        if(k == 1){
            cout<<"YES"<<endl;
            for(int i = 1;i <= n;i++){
                cout<<i<<endl;
            }
            continue;
        }
        if((n == 1) && (k != 1)){
            cout<<"NO"<<endl;
            continue;
        }
        if(n % 2  == 1){
            cout<<"NO"<<endl;
            continue;
        }
        else if(n % 2 == 0){
            cout<<"YES"<<endl;
            solve(n,k);
            continue;
        }
    }
    return 0;
}

void solve(int n, int k){ // row (2*n-1 -> 2*n ,k)
    for(int i = 1; i <= k; i++){
        ans[1][i]=2*i-1;
        ans[2][i]=2*i;
    }
    for(int i = 1; 2*i<=n;i++){
        for(int j = 1; j <= k;j++){
            cout<<ans[1][j]<<' ';
            ans[1][j]+=2*k;
        }
        cout<<endl;
        for(int j = 1; j <= k;j++){
            cout<<ans[2][j]<<' ';
            ans[2][j]+=2*k;
        }
        cout<<endl;
    }
}