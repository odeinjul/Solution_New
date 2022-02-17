//P means pass
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
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
        fflush(stdout);
    }
    fflush(stdout);
    return 0;
}

//cout.flush()

void work(int n){
    int flag1, flag2, temp;
    int i = 1, j = 2;
    maxn = -2; temp = 0;
    for(int k = 3; k <= n; k++){
        cout << "? " << i << ' ' << j << ' ' << k <<endl;
        cout.flush();
        cin>>temp;
        if(temp >= maxn){
            maxn = temp;
            flag1 = k;
        }
    }
    maxn = -2; temp = 0;
    j = flag1;
    for(int k = 3; k <= n; k++){
        if(k == flag1)
            continue;
        cout << "? " << i << ' ' << j << ' ' << k <<endl;
        cout.flush();
        cin>>temp;
        if(temp >= maxn){
            maxn = temp;
            flag2 = k;
        }
    }
    int a = 1, b = flag1, c = flag2;
    int d = 2;
    int aa = a, bb = b, cc = c;
    while(d == a || d == b || d == c){
        d++;
    }
    a = d;
    int temp1,temp2,temp3;
    cout << "? " << a << ' ' << b << ' ' << c <<endl;
    cin >> temp1 ;
    a = aa;
    b = d;
    cout << "? " << a << ' ' << b << ' ' << c <<endl;
    cin >> temp2 ;
    b = bb;
    c = d;
    cout << "? " << a << ' ' << b << ' ' << c <<endl;
    cin >> temp3 ;
    c = cc;
    //cout<< temp1 << ' ' << temp2 << ' ' <<temp3 << ' '<<maxn<<endl;
    if(temp1 == maxn && temp1 > temp2 && temp1 > temp3){
        cout << "! " << b << ' '<< c << endl;
        return ;
    }
    else if(temp2 == maxn && temp2 > temp1 && temp2 >temp3){
        cout << "! " << a << ' '<< c << endl;
        return ;
    }
    else if(temp3 == maxn && temp3 > temp1 && temp3 >temp2){
        cout << "! " << a << ' '<< b << endl;
        return ;
    }
    else if(temp1 == temp3){
        cout << "! " << b << ' '<< d << endl;
        return ;
    }
    else if(temp2 == temp3){
        cout << "! " << a << ' '<< d << endl;
        return ;
    }
    else if(temp2 == temp1){
        cout << "! " << c << ' '<< d << endl;
        return ;
    }
    return ;

}