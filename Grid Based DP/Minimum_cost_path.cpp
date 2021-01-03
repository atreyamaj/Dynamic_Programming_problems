/*
QUESTION:

Given a cost matrix, where cost[i][j] = 5 means it will cost 5 units to cross the (i,j)'th position,
Find the minimum cost to traverse the grid from the start point to the end point.

From any cell, you can either move towards the right, or move down.

Therefore, you can either enter a new cell from the top or the left.

*/

#include<bits/stdc++.h>
#include<iostream>
#include<cmath>

using namespace std;

int cost(int R, int C, int dp[][3], int cost[][3]){
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            if(i == 0 and j == 0){
                dp[i][j] = cost[0][0];  // First cell cost =  value of first cell
            }
            else if(i == 0){
                dp[i][j] = cost[0][j-1] + cost[0][j];  // If row = 0, then you can only come in from the left.
            }
            else if(j == 0){
                dp[i][j] = cost[i-1][0] + cost[i][0]; // If col == 0, then can only come in from the top.
            }
            else{
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + cost[i][j]; // Calculating minimum path to top cell and left cell, 
                                                                      // then adding current cost.
            }
            //Order O(n^2)
        }
    }
    return dp[R-1][C-1];
}

int main(){
    return 0;
}