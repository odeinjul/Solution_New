#include <iostream>
#include <cstring>
using namespace std;
int find(int x);
void merge(int x, int y);
int fa[100010] = {0},ranks[100010]={0};
int check(int a, int b);
int main(){
    int t = 0, n, temp[100010], cnt = 0;
    cin >> t;
    while(t--){
        cin >> n;
        cnt = 0;
        for(int i = 1; i <= n; i++){
            cin >> temp[i];
            fa[i] = i;
            ranks[i] = 1;
        }   
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(temp[i]>temp[j]){
                    if(!check(i,j)){
                        cnt++;
                    }
                }
            }
        }
        cout << n - cnt << endl;
    }
}
int check(int a, int b){
    int af = find(a);
    int bf = find(b);
    if(af == bf)
        return 1;
    else{
        int x,y;
        x=af,y=bf;
        if (ranks[x] <= ranks[y])
            fa[x] = y;
        else
            fa[y] = x;
        if (ranks[x] == ranks[y] && x != y)
            ranks[y]++;  
        return 0;
    }
}
int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}