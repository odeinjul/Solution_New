//P means pass
#include <iostream>
#include <cstring>
using namespace std;
void work(int n);
int maxn = -2;
int help(int i,int j,int n);
int main(){
    int t = 0, n;
    cin >> t;
    for(int a = 0; a < t; a++){
        cin >> n;
        work(n);
    }
    return 0;
}

//cout.flush()

void work(int n){
    int flag1,flag2;
    flag1 = help(2, n-1, n);
    flag2 = help(flag1, n-1, n);
    int a,b,c;
    cout << "? " << 2 << ' ' << n-1 << ' ' << flag1 <<endl;
    cout.flush();
    cin >> a;
    cout << "? " << flag2 << ' ' << 2 << ' ' << flag1 <<endl;
    cout.flush();
    cin >> b;
    cout << "? " << 2 << ' ' << n-1 << ' ' << flag2 <<endl;
    cout.flush();
    cin >> c;
    if(maxn == a){
        cout<<"! "<<flag1<<' '<<n-1<<endl;
    }
    else if(maxn == b){
        cout<<"! "<<flag1<<' '<<n-1<<endl;
    }
    else if(maxn == c){
        cout<<"! "<<n-1<<' '<<flag2<<endl;
    }
    else if(a == b){
        cout<<"! "<<flag2<<' '<<flag1<<endl;
    }
    else if(a == c){
        cout<<"! "<<flag2<<' '<<flag1<<endl;
    }
    else if(c == b){
        cout<<"! "<<flag2<<' '<<n-1<<endl;
    }
    cout.flush();
}

int help(int i, int j, int n){
    int temp = 0, flag = 0;
    maxn = -2;
    int cnt = 0;
    for(int k = 1; k <= n; k++){
        if(k == i || k == j)   
            continue;
        cout << "? " << i << ' ' << j << ' ' << k <<endl;
        cout.flush();
        cin >> temp;
        if(temp == maxn){
            cnt ++;
        }
        if(temp > maxn){
            maxn = temp;
            flag = k;
        }
    }
    //cout<<cnt<<' '<<i<<' '<<endl;
    return flag;//temp;
}