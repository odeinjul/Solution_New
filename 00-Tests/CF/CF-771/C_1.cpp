#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int t = 0, n, temp[100010], cnt = 0, maxn=0, index;
    cin >> t;
    while(t--){
        cin >> n;
        cnt = 0;
        for(int i = 1; i <= n; i++){
            cin >> temp[i];
        }
        index =0;
        for(int i = n; i >= 1;i=index-1){
            cnt++;
            //cout<<"HELLO"<<endl;
            //cout<<temp[3]<<endl;
            //cout<<i<<' '<<temp[i]<<' '<<cnt<<' '<<index<<endl;
            maxn=-1;
            index = 0;
            for(int j=i;j>=1;j--){
                if(temp[j]>maxn){
                    maxn=temp[j];
                    index = j;
                }
            }
            if(i==1)
                break;
        }
        cout << cnt << endl;
    }
}