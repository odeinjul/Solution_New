#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int t = 0, x1,x2,x3,y1,y2,y3;
    cin >> t;
    while(t--){
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>x3>>y3;
        if(y1 == y2){
            if(y3 < y1){
                cout << abs(x2-x1)<< endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else if(y1 == y3){
            if(y2 < y1){
                cout << abs(x1-x3) << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else if(y2 == y3){
            if(y1 < y2){
                cout << abs(x2-x3) <<endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}
