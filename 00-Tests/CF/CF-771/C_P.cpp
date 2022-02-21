// Inversion Graph
#include <iostream>
#include <stack>
using namespace std;

void solve(void);

int main(void){
    int test;
    cin >> test;
    while (test--)
        solve();
    return 0;
}

void solve(void){
    int n, t;
    stack<int> stk; //only save the maximum of each connected component
    cin >> n;
    for(int i = 1; i <=n; i++){
        cin >> t;
        if(stk.empty()){
            stk.push(t); 
        }
        if(stk.top() < t){
            stk.push(t);  //t should be put into the top of the stack
        }
        else{
            int stk_top = stk.top();  //save the top of the stack
            while(!stk.empty() && stk.top() > t){ //if top is smaller than t, this compoment is connected with the previous one
                stk.pop();
            }
            stk.push(stk_top); //push back the top of the stack
            //the stack should be no decreasing
        }
    }
    cout << stk.size() <<endl;
}