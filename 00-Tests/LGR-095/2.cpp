#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
//#define int long long
int n,d;
int init(){
	char c = getchar();
	int x = 0, f = 1;
	for (; c < '0' || c > '9'; c = getchar())
		if (c == '-') f = -1;
	for (; c >= '0' && c <= '9'; c = getchar())
		x = (x << 1) + (x << 3) + (c ^ 48);
	return x * f;
}
void print(int x){
	if (x < 0) x = -x, putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}
int main(){
	n = init(); d = init();
    /*if(2n-d-1 < (n/2+1)){
        print(-1);
        return 0;
    }*/
	print(-1); // output a number
    return 0;
}