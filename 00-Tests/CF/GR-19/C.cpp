#include <iostream>
#include <cstring>
using namespace std;
int main(){
    long long t = 0, n = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, a = 0, sum = 0;
    cin >> t;
    while(t --){
        cnt1 = 0; cnt2 = 0; cnt3=0; a = 0; sum = 0;
        cin >> n;
        cin>>a;
        for(int i = 1;i < n-1; i++){
            cin>>a;
            if(a==1){
                cnt1++;
            }
            else if(a%2==1){
                cnt3++;
            }
            else if(a%2==0){
                cnt2++;
            }
                sum+=a;
        }
        cin>>a;
        //cout<<cnt1<<' '<<cnt2<<' '<<cnt3<<' '<<sum<<endl;
        if(n==3){
            if(sum%2==0){
                cout<<sum/2<<endl;
            }
            else{
                cout<<"-1"<<endl;
            }
        }
        else{
            if((cnt3+cnt2)==0){
                cout<<"-1"<<endl;
            }
            else{
                cout<<(sum+cnt3+cnt1)/2<<endl;
            }
        }
    }
    return 0;
}
