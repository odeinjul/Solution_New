//TRASH 
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
    int flag1, flag2;
    if(n == 4){
        int a = 0, b = 0, c = 0, d = 0;
        cout << "? 1 2 3" << endl;
        cout.flush();
        cin >> a;
        cout << "? 4 2 1"<< endl;
        cout.flush();
        cin >> b;
        cout << "? 1 3 4" << endl;
        cout.flush();
        cin >> c;
        cout << "? 4 2 3" << endl;
        cout.flush();
        cin >> d;
        //cout<<a<<" "<<b <<" "<<c<<" "<<d<<endl;
        if(a == b && b >= c){
            //cout<<a<<" "<<b <<" "<<c<<" "<<d<<endl;
            cout << "! 1 2" << endl;
            cout.flush();
        }
        else if(a == c && c >= b){
            cout << "! 1 3" << endl;
            cout.flush();
        }
        else if(a == d && d >= b){
            cout << "! 2 3" << endl;
            cout.flush();
        }
        else if(b == c && b >= a){
            cout << "! 1 4" << endl;
            cout.flush();
        }
        else if(b == d && b >= a){
            cout << "! 2 4" << endl;
            cout.flush();
        }
        else if(c == d && c >= a){
            //cout<<a<<" "<<b <<" "<<c<<" "<<d<<endl;
            cout << "! 4 3" << endl;
            cout.flush();
        }
    }
    else{
        flag1 = help(2, n-1, n);
        if(flag1 == -1){
            flag1 = 2;
            flag2 = help(1, 2, n);
        }
        else

            flag2 = help(flag1, 2, n);
        cout << "! " << flag1 << ' ' << ((flag2 == -1)?1:flag2)<< endl;
        cout.flush();
    }
    return ;
}
int help(int i, int j, int n){
    int maxn = -1, temp = 0, flag = 0;
    int cnt = 0;
    for(int k = 1; k <= n; k++){
        if(k == i || k == j)   
            continue;
        cout << "? " << i << ' ' << j << ' ' << k <<endl;
        cout.flush();
        cin>>temp;
        if(temp == maxn){
            cnt ++;
        }
        if(temp > maxn){
            maxn = temp;
            flag = k;
        }
    }
    //cout<<cnt<<' '<<i<<' '<<endl;
    if(cnt == n-3)
        return -1;
    else
        return flag;
}