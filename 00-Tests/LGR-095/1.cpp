#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
//#define int long long
int n,x,y,k;
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
int gcd(int x,int y){
    if(y==0)return x;
    int x0=x%y;
    return gcd(y,x0);
}
int main(){
	n = init(); k = init(); x = init(); y = init();
    int tmp = gcd(2*n*2*n,k);
    print(2*n*2*n/tmp);
    //print(x); // output a number
    return 0;
}