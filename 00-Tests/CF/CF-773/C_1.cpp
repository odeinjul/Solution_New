#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int bi_sec(int l, int r, int q);
int a[200111],flag[200111];
int main(){
    int t = 0, n,x,cur_1,cur_2,cnt;
    cin >> t;
    while(t--){
        cnt = 0;
        memset(flag,0,sizeof(flag));
        cin >> n >> x;
        for(int i=1; i<=n;i++){
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        cur_1 = 1; cur_2 = bi_sec(1,n,x*a[1]);

        while(a[cur_2-1]==a[cur_2]&&a[cur_2]==x*a[cur_1]){
            cout<<a[cur_2]<<' aa '<<x*a[cur_1]<<endl;
            cur_2--;//get minnum of cur_2
        }
        cout<<cur_1<<"  "<<cur_2<<endl;
        int save_cur_2 = cur_2;
        while(cur_2 <= n){
            if(cur_1==save_cur_2){
                //find new cur_2 and swap c_1 c_2
                cur_2 = bi_sec(cur_2+1,n,x*a[cur_2]);
                while(a[cur_2-1]==a[cur_2]&&a[cur_2]==x*a[cur_1]){
                    cur_2--;//get minnum of cur_2
                }
                if(a[cur_2]==x*a[cur_1]){
                    cur_2 = cur_2;
                    cur_1 = save_cur_2+1;
                }
                else if(a[cur_2]>x*a[cur_1]){
                    cur_2 = cur_2-1;
                    cur_1 = save_cur_2+1;
                }
                else{
                    if(cur_2+1==n){
                        cur_2=n;
                        cur_1=save_cur_2+1;
                    }
                    else{
                        cur_2 = cur_2;
                        cur_1 = save_cur_2+1;
                    }
                }
            }
            cout<<cur_1<<"  "<<cur_2<<endl;
            cout<<flag[cur_1]<<"  "<<flag[cur_2]<<endl;
            cout<<a[cur_1]<<"  "<<a[cur_2]<<endl;
            while(flag[cur_1]==1){
                cur_1++;
            }
            while(flag[cur_2]==1){
                cur_1++;
            }
            if(a[cur_1]==a[cur_2]){
                cur_2++;cur_1++;
                flag[cur_1]=flag[cur_2]=1;
                cnt+=2;
            }
            else if (a[cur_1]<a[cur_2]){
                cur_1++;
            }
            else if(a[cur_1]>a[cur_2]){
                cur_2++;
            }
            cout<<flag[cur_1]<<"  "<<flag[cur_2]<<endl;
            cout<<a[cur_1]<<"  "<<a[cur_2]<<endl;
            cout<<"-----------------"<<endl;
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