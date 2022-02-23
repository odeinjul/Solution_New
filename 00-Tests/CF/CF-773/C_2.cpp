#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int bi_sec(int l, int r, int q);
int a[200111],flag[200111],cur[200111];
int main(){
    int t = 0, n,x,cnt;
    cin >> t;
    while(t--){
        cnt = 0;
            memset(flag,0,sizeof(flag));
            cin >> n >> x;
            for(int i=1; i<=n;i++){
               cin >> a[i];
            }
            sort(a+1,a+n+1);
            cur[1]=1;
            int cur_n = 1;
            for(int i=2;i<=n;i++){
                //cout<<a[i]<<' '<<cur[cur_n]<<' '<<a[cur[cur_n]]<<endl;
                if(a[i]==a[cur[cur_n]]*x){
                    cur[cur_n+1]=i;
                    cur_n++;
                    cout<<cur[cur_n-1]<< ' '<<a[cur[cur_n-1]]<<endl;
                }
                else if(a[i]>a[cur[cur_n]*x]){
                    cur[cur_n+1]=i-1;
                    cur_n++;
                }
            }
            cur[cur_n+1]=n+1;
            cur_n++;
            cout<<cur_n<<endl;
            for(int i=1;i<=cur_n;i++){
                cout<<cur[i]<<' ';
            }
            cout<<endl;
                int cur_s=1;
            int l1=cur[cur_s];
            int l2=cur[cur_s+1];
            int l3=cur[cur_s+2];
                int save_l1=l1=cur[cur_s];
                int save_l2=l2=cur[cur_s+1];
                int save_l3=l3=cur[cur_s+2];
            if(cur_n>=3){
            while(1){
                cout<<' '<<l1<<' '<<l2<<' '<<l3<<endl;
                if(l3==n+1&&(l2==l1||l2==l3)){
                    break;
                }
                if(l1==l2||l2==l3){
                    cur_s++;
                    l1=cur[cur_s];
                    l2=cur[cur_s+1];
                    l3=cur[cur_s+2];
                }
                if(a[l1]==a[l2]&&flag[l1]==0&&flag[l2]==0){
                    l1++;l2++;cnt+=2;
                    flag[l1]=flag[l2]=1;
                }
                else if(a[l1]>a[l2]){
                    l2++;
                }
                else if(a[l2] > a[l1]){
                    l1++;
                }
            }
            }
            else{
                if((l2==l1||l2==n+1)){
                    break;
                }
                if(l1==l2||l2==l3){
                    cur_s++;
                    l1=cur[cur_s];
                    l2=cur[cur_s+1];
                    l3=cur[cur_s+2];
                }
                if(a[l1]==a[l2]&&flag[l1]==0&&flag[l2]==0){
                    l1++;l2++;cnt+=2;
                    flag[l1]=flag[l2]=1;
                }
                else if(a[l1]>a[l2]){
                    l2++;
                }
                else if(a[l2] > a[l1]){
                    l1++;
                }
            }
            cout<<endl;
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