/*
QUESTION:

We have a robot that can move in a grid of size MxN. 
The robot is initially positioned at (1,1) ---> First cell of the grid.

The bot has to move to the (M,N) grid cell.
The bot can only move to cells to its immediate east or immediate south.

Obstacles have been placed in the grid in cells which the robot cannot pass.

OUTPUT:
Count the number of paths the robot can take to move from (1,1) to (M,N). 
Output the answer modulo 1000000007

*/

#include<bits/stdc++.h>
#include<iostream>
#include<cmath>

#define MOD 1000000007;

using namespace std;

int dp[1001][1001];

int numWays(int Row, int Col){ 
    //Base Case
    if(dp[0][0] == -1){ // First cell where we start from is blocked, so can't move at all.
        return 0;
    }

    // Compute number of ways for first row.
    for(int j = 0; j < Col; j++){
        if(dp[0][j] == -1){
            break; // If obstacle is encountered horizontally, cannot move further in that row. Thus, breaking.
        }
        dp[0][j] = 1;
    }

    // Compute number of ways for first column.
    for(int i = 0; i < Row; i++){
        if(dp[i][0] == -1){
            break; // If obstacle is encountered horizontally, cannot move further in that row. Thus, breaking.
        }
        dp[i][0] = 1;
    }

    // Bottom Up approach for the rest of the matrix
    for(int i = 1; i<Row; i++){
        for(int j = 1; j < Col; j++){

            //If cell is blocked, leave it and go to the next cell
            if(dp[i][j] == -1){
                continue;
            }

            dp[i][j] = 0;

            if(dp[i][j-1] != -1){
                dp[i][j] = dp[i][j-1] % MOD;
            }

            if(dp[i-1][j] != -1){
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            }
        }

        //Check for final cell
        if(dp[Row-1][Col-1] == -1){
            return 0; //Cannot reach final cell
        }
    }

    //Print DP table
    for(int i = 0; i< Row; i++){
        for(int j = 0; j< Col; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //Return answer
    return dp[Row-1][Col-1];
}


int main(){
    memset(dp, 0 , sizeof dp);

    int M, N, P;
    cin>>M>>N>>P;

    for(int i = 0; i< P; i++){
        int X,Y;
        cin>>X>>Y;
        dp[X-1][Y-1] = -1; // -1 signifies blocks
    }

    cout<<numWays(M,N)<<endl;
    return 0;
}