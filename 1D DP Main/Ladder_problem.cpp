/*
There is a Ladder with n steps.
Need to find the number of ways to reach the top.  ---> OUTPUT

The person can take a maximum jump of k at each step.

k ---> INPUT
*/

#include<bits/stdc++.h>
using namespace std;

int Ladder_topdown(int n, int k, int dp[]){
    //Base case
    if (n == 0) {
        return 1;
    }
    
    // Look up
    if(dp[n]!=0) {
        return dp[n];
    }
    
    //Recursive case
    int ways = 0;
    for(int i = 1; i<= k; i++){
        if(n - i >= 0){
            ways += Ladder_topdown(n-i, k, dp);
        }
    }
    return dp[n] = ways;
}

int Ladder_bottomup(int n, int k){
    int dp[100] = {0};
    dp[0] = 1;
    for(int i = 1; i<=n; i++){
        dp[i] = 0;
        for(int j = 1; j<=k; j++){
            if(i-j>=0){
                dp[i] += dp[i-j];
            }
        }
    }
    return dp[n];
}



int main(){
    int n,k;
    cin>>n>>k;
    int dp[100] = {0};
    cout<<"Top-Down Ways = " <<Ladder_topdown(n,k,dp)<<endl;
    cout<<"Bottom-Up Ways = " <<Ladder_bottomup(n,k)<<endl;
    return 0;
}