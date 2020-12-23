#include<iostream>
#include<climits>

using namespace std;

int minsteps_topdown(int n, int dp[]){
    //Base case
    if(n == 1){
        return 0;
    }
    //Look up if already computed
    if(dp[n] != 0){
        return dp[n];
    }
    //Recursive Case
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;

    if(n%3 == 0){
        op1 = minsteps_topdown(n/3, dp) + 1;
    }
    if(n%2 == 0){
        op2 = minsteps_topdown(n/2, dp) + 1;
    }
    op3 = minsteps_topdown(n-1, dp) + 1;
    int ans = min(min(op1, op2), op3);
    return dp[n] = ans;

}

int minsteps_bottomup(int n){
    int dp[100] = {0};
    dp[1] = 0;
    for(int i = 2; i<= n; i++){
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;
        if(n%3 == 0){
            op1 = dp[i/3];
        }
        if(n%2 == 0){
            op2 = dp[i/2];
        }
        op3 = dp[i-1];
        dp[i] = min(min(op1,op2), op3) + 1;
    }
    return dp[n];

}

int main(){
    int n;
    cin>>n;
    int dp[100] = {0};
    //cout<<minsteps_topdown(n, dp)<<endl;
    cout<<minsteps_bottomup(10)<<endl;
}