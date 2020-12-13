#include<iostream>
using namespace std;

// Fibonacci till nth number using Top-Down Approach

int fib(int n){ //recursion
    
    if( n == 1 or n == 0) return n;
    int ans = fib(n - 1) + fib(n-2);
    return ans;
}

int fib_dp(int n, int dp[]){
    if (n == 0 or n == 1) return n;

    //Look up
    if(dp[n] != 0){
        return dp[n];
    }

    int ans;
    ans = fib_dp(n-1, dp) + fib_dp(n-2, dp);
    return dp[n] = ans;
}

int main(){
    int n;
    
    cout<<"Enter N: "<<endl;
    int dp [100] = {0};
    cin>>n;
    cout<<fib_dp(n, dp)<<endl;
}