#include <iostream>
#include <cstring>
using namespace std;
int temp[110];
int helper(int l, int r, int l0, int r0, int index);
int main(){
    int t = 0, n = 0, l = 0, r = 0, sum = 0;
    cin >> t;
    while(t --){
        sum = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> temp[i];
        }
        for(int l = 0; l < n; l++){
            for(int r = n-1; r >= l; r--){
                //[l..r]
                int minn = 0x7fffffff,index;
                int ans = 0;
                for(int i = 0; i <= n-1; i ++){
                    if(minn > temp[i]){
                        minn = temp[i];
                        index = i;
                    }
                }
                int t0;
                //cout<<l<<' '<<r<<' '<<index<<endl;
                if(index < l || index > r){
                    t0 = (l-r+1)*(1+minn);
                }
                else{
                    t0 = helper(0, n-1, l, r, index);
                }
                //cout<<"t0 "<<t0<<endl;
                sum += t0;
            }
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}

int helper(int l, int r, int l0, int r0, int index){
    //cout<<l<<' '<<r<<' '<<l0<<' '<<r0<<' '<<index<<endl;
    int minn = temp[index];
    if(l0 == r0){
        //cout<<"a"<<endl;
        int minn0 = 0x7fffffff;
            for(int i = l; i <= r; i ++){
                    if(minn0 > temp[i] && i != r0){
                        minn0 = temp[i];
                    }
                }
        //cout<<"E "<<1+minn0<<endl;
        return 1+minn0;
    }
    else if ( l0 == index ){
        //cout<<"b"<<endl;
        int a = helper(l,r,l0,l0,index);
        int b = (r0-l0)*(minn + 1);
        //cout<<"E "<<a+b<<endl;
        return a+b;
    }
    else if ( r0 == index ){
        //cout<<"c"<<endl;
        int a = helper(l,r,r0,r0,index);
        int b = (r0-l0)*(minn + 1);
        //cout<<"E "<<a+b<<endl;
        return a+b;
    }
    //cout<<"d"<<endl;
    int c = helper(l, r, index, r0, index);
    int a =(index - l0)*(1+minn);
    int b =(r0-index)*(1+minn);
    int d =helper(l, r, l0, index, index);
    //cout<<"E "<<max(a+c, b+d)<<endl;
    int ans = max(a+c, b+d);
    //cout<<ans<<endl;
    return ans;
    /*int minn = 0x7fffffff,index;
    int ans = 0;
    for(int i = l; i <= r; i ++){
        if(minn > temp[i]){
            minn = temp;
            index = i;
        }
    }
    //temp_i is the min
    //ans = (r - l)*minn + (r-l + 1) + minn2
    ans = helper(l, index - 1)
    
    (r-l)*minn + (r-l+1) + minn2;
    [l..index+1]+

    */
    
}