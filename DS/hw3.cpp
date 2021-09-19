#include<iostream>
#include<cstring>
using namespace std;
int compute(string a){
    int number = 0, sum = 0,flag = 1;
    for(int i = 0; i < a.length(); i++){
  	    char now = a[i];
        if('1' <= now && now <= '9'){
            number = (number) * 10 + (now - '0');
        }
        else{
        	if(flag == 1){
                sum += number;
                number = 0;
            }
            else{
                sum -= number;
                number = 0;
            }
            if(now == '+')
                flag = 1;
            else if(now == '-')
                flag = -1;
        }    
    }
    if(flag == 1){
        sum += number;
        number = 0;
    }
    else{
        sum -= number;
        number = 0;
    }
    return sum;
}
void helper(string temp, int n){
    if(n == 9){
        temp += '9';
        if(compute(temp) == 110){
            cout<<temp<<" = 110"<<endl;
            return ;
        }
        //cout<<temp<<endl;
        return ;
    }
    temp += (char)('0'+n);
    helper(temp + '+', n+1);
    helper(temp + '-', n+1);
    helper(temp, n+1);
    return ;
}
void work(){
    string temp="";
    helper(temp, 1);
}
int main(){
    work();
    return 0;
}