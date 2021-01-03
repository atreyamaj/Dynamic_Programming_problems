/*
QUESTION:

In a given grid, Find the number of ways to reach a particular position from a given starting point.

You have to do this for 2 animals:
1. Rat ---> Moves Right and Down, 1 step each
2. Elephant (Chess) ---> Right and DOwn, K steps each.
*/

#include<bits/stdc++.h>
#include<iostream>
#include<cmath>

using namespace std;

int rat(int R, int C, int dp[][3], int cost[][3]){ // Bottom Up ---> Simpler
    
    /* Recursively:

    ans = factorial(R - 1 + C - 1) / ( factorial(M-1) * factorial(N-1) )
    */

    //Moving on to Bottom Up:
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(i == 0){
                dp[0][j] = 1;
            }
            else if(j == 0){
                dp[i][0] = 1;
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1]; // Calculating total number of ways to reach.
            }
        }
    }
}


int main(){
    return 0;
}