// Given an array of wine bottles, where the ith element is the price of the ith bottle, 
// In 1 year you can sell 1 bottle, and you can only sell a bottle at either end of the shelf/array 
//(either extreme left bottle or extreme right bottle)
// Prices of wines increase every year 
// In the yth year, price of bottle becomes p[i] * y

//This is a 2D DP problem because we have 2 variables to take care of here: 
//the start variable and the end variable of the wine array


#include<iostream>
#include<climits>

using namespace std;

int profit(int wines[], int i, int j, int y){//Recursive Solution
    // y is the year--> keep updating y to y+1
    //Base case - No bottles left:
    //This will happen when i>j therefore profit will be 0
    if(i>j) return 0;

    //Recursive Case
    //2 options: sell bottle at ith position or jth position
    int op1 = wines[i]*y + profit(wines, i+1, j, y+1);
    int op2 = wines[j]*y + profit(wines, i, j-1, y+1);

    //Now return max of the 2 options
    return max(op1, op2);
    
}

int wine_dp(int wines[], int i, int j, int y, int dp[][100]){
    //Base
    if(i>j) return 0;
    //Lookup
    if(dp[i][j]!= 0 ) return dp[i][j];
    //Compute
    int op1 = wines[i]*y + wine_dp(wines, i+1, j, y+1, dp);
    int op2 = wines[j]*y + wine_dp(wines, i, j-1, y+1, dp);
    return dp[i][j] = max(op1, op2);
}

int main(){
    int wines[] = {2,3,5,1,4};
    int dp[100][100] = {0};
    int n = sizeof(wines)/sizeof(int);
    int y = 1;
    //cout<<profit(wines, 0, n-1, y)<<endl;
    cout<<wine_dp(wines, 0, n-1, y, dp)<<endl;
}