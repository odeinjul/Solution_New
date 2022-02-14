#include <iostream>
#include <cstring>
using namespace std;
int a[510];
void reverse(int l, int r, int n);
int main(){
    int t = 0, n, l = 0 ,r = 0, temp = 0;
    cin >> t;
    while(t--){
        cin >> n;
        if(n==1){
            cin>>n;
            cout<<n<<endl;
            continue;
        }
        l = r = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] > i && l == 0){
                l = i;
            }
            if(l != 0 && a[i] == l){
                r = i;
            }
        }
        if(l==0){
            for(int i = 1; i <= n; i++){
                cout<<a[i]<<' ';
            }
            cout<<endl;
            continue;
        }
        reverse(l, r, n);
    }
    return 0;
}

void reverse(int l, int r, int n){
    for(int i = 1; i < l; i++){
        cout<<a[i]<<' ';
    }
    for(int i = r; i >= l; i--){
        cout<<a[i]<<' ';
    }
    for(int i = r + 1; i <=n; i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}