#include <iostream>
#include <cstring>
using namespace std;
void work(int n);
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
    cout << "! " << flag1 << ' ' << ((flag2 == -1)?n-1:flag2 )<< endl;
    cout.flush();
}

int help(int i, int j, int n){
    int maxn = -2, temp = 0, flag = 0;
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
    if(cnt == n-3 && i != 2)
        return -1;
    else
        return flag;
}