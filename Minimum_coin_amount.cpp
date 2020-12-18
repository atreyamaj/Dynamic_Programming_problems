//You have coins of different values
// You have to reach the target amount with the minimum number of coins possible

#include<iostream>
#include<climits>

using namespace std;

int minCoins_TD(int n, int coins[], int T, int dp[]){ // T is the number of types of coins
    //Base case
    if (n == 0){
        return 0;
    }
    //Look up:
    if(dp[n]!= 0){
        return dp[n];
    }
    //Recursive:
    int ans = INT_MAX;
    for(int i = 0; i <T; i++){
        if(n-coins[i] >= 0){
            int subproblem = 1 + minCoins_TD(n-coins[i], coins, T, dp);
            ans = min(ans, subproblem);
        }
    }
    return dp[n] = ans;
}

int minCoins_BU(int N,int coins[], int T){
    int dp[100] = {0};
    // Iterate over all states from 1 to N
    for(int n = 1; n<= N; n++){
        dp[n] = INT_MAX;
        for(int i = 0; i<T; i++){
            if(n - coins[i] >= 0){
                int subproblem = 1+ dp[n - coins[i]];
                dp[n] = min(dp[n], subproblem);
            }
        }
    }
    return dp[N];
}


int main(){
    int N = 15; //Target
    int coins[] = {1,7,10}; //Coins of different values: 1,7,10
    int dp[100] = {0};
    int T = sizeof(coins) / sizeof(int);
    //cout<<minCoins_TD(N,coins, T, dp)<<endl;
    cout<<minCoins_BU(N,coins, T)<<endl;
    return 0;
}
