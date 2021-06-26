#include <iostream>
#include <cstdio>
using namespace std;
int n,m;
int arr[510][510];
void start(int n){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            arr[i][j]=n*(i-1)+j;
}
void act(int x,int y,int r,int z){
    int temp[510][510];
    if(z != 0){
        for(int i = x-r;i <= x+r;i++){
            for(int j = y-r;j <= y+r;j++){
                temp[i][j] = arr[i][j];
            }
        }  
        int y0 = y+r,x0 = x-r;
        for(int i = x-r;i <= x+r;i++){
            for(int j = y-r;j <= y+r;j++){
                arr[i][j] = temp[x0][y0];
                x0++;
            }
            y0--;
            x0 = x-r;
        }      
    }
    else{
        for(int i = x-r;i <= x+r;i++){
            for(int j = y-r;j <= y+r;j++){
                temp[i][j] = arr[i][j];
            }
        }  
        int y0 = y-r,x0 = x+r;
        for(int i = x-r;i <= x+r;i++){
            for(int j = y-r;j <= y+r;j++){
                arr[i][j] = temp[x0][y0];
                x0--;
            }
            y0++;
            x0 = x+r;
        }   
    }
}
void ans(int n){
    for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
            cout<<arr[i][j];
            if(j!=n)
                cout<<' ';
         }
        cout<<endl;
    }   
}
int main(){
    int x,y,r,z;
    cin>>n>>m;
    start(n);
    for(int i=0;i<m;i++){
        scanf("%d %d %d %d",&x,&y,&r,&z);
        act(x,y,r,z);
    }
    ans(n);
    return 0;
}

//模拟 要注意数组顺序（坐标系原点及方向的定位）