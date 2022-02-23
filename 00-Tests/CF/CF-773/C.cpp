#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int bi_sec(int l, int r, int q);
int a[200111],flag[200111];
int main(){
    int t = 0, n,x,cur_f,cur_e,cnt;
    cin >> t;
    while(t--){
        cnt = 0;
        memset(flag,0,sizeof(flag));
        cin >> n >> x;
        cur_f = 1; cur_e=0;
        for(int i = 1; i <= n ; i++){
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        cur_e = bi_sec(1,n,x*a[1]);
        int save_cur_e = cur_e;
        while(a[cur_e-1]==a[cur_e]){
            cur_e--;
        }
        //cout<<"cur_e "<<cur_e<<endl;
        for(int i = 1; i<=n;i++){
            //cout<<"cur: "<<cur_e<<endl;
            if(flag[i]==1){
                ;
            }
            else{
                if(a[i]*x == a[cur_e]&&flag[cur_e]==0){
                    flag[i]=flag[cur_e]=1;
                    cnt+=2;
                    //cout<<"a "<<i << ' '<<cur_e<<endl;
                    cur_e++;
                }
                else if(a[i]*x > a[cur_e]){
                    cur_e=bi_sec(cur_e+1,n,a[i]*x);
                    if(a[cur_e]==a[i]*x&&flag[cur_e]==0){
                        flag[i]=flag[cur_e]=1;
                        cnt+=2;
                        //cout<<"b "<<i << ' '<<cur_e<<endl;
                        cur_e++;
                    }
                }
                else if(a[i]*x < a[cur_e]){
                    cur_e=bi_sec(i+1,cur_e-1,a[i]*x);
                    if(a[cur_e]==a[i]*x &&flag[cur_e]==0){
                        flag[i]=flag[cur_e]=1;
                        cnt+=2;
                        //cout<<"c "<<i << ' '<<cur_e<<endl;
                        cur_e++;
                    }
                }
            }
            //cout<<a[i]<<" "<<flag[i]<<endl;
        }
        cout<<n-cnt<<endl;
    } 
    return 0;
}
int bi_sec(int l, int r ,int q){
    int mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(a[mid] == q){
            return mid;
        }
        else if(a[mid] < q){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return mid;
}