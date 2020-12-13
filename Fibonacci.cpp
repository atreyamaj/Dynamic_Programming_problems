#include<iostream>
using namespace std;

// Q) Fibonacci till nth number using Top-Down Approach

int fib(int n){ //recursion
    
    if( n == 1 or n == 0) return n;
    int ans = fib(n - 1) + fib(n-2);
    return ans;
}

int fib_topdown(int n, int dp[]){
    if (n == 0 or n == 1) return n;

    //Look up
    if(dp[n] != 0){
        return dp[n];
    }

    int ans;
    ans = fib_topdown(n-1, dp) + fib_topdown(n-2, dp);
    return dp[n] = ans;
}

int fib_bottomup(int n){
    int dp[n+1] = {0};
    dp[1] = 1;
    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int space_optimize(int n){
    if(n == 0 or n == 1) return n;
    int a = 0;
    int b = 1;
    int c;
    for(int i = 2; i<= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n;
    
    cout<<"Enter N: "<<endl;
    int dp [100] = {0};
    cin>>n;
    cout<<fib_topdown(n, dp)<<endl;
    cout<<fib_bottomup(n)<<endl;
    cout<< space_optimize(n)<<endl;
}