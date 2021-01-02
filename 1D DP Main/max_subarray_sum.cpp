/*
QUESTION: 
Form the maximum sum of a subarray possible from a given array.


*/

#include<iostream>
#include<climits>
#include <bits/stdc++.h>
using namespace std;

int MaxSum(int a[], int n){ // Bottom up DP
    int dp[100] = {0};
    dp[0] = a[0]>0 ? a[0]:0;
    int max_so_far = dp[0];

    for(int i = 1; i<n; i++){
        dp[i] = dp[i-1] + a[i];
        if(dp[i] < 0){
            dp[i] = 0;
        }
        max_so_far = max(dp[i], max_so_far);
    }
    return max_so_far;
}

//Optimize space efficiency now
//Kadane's Algorithm

int maxsum_opt(int arr[], int n){
    int current_sum = 0;
    int max_so_far = 0;
    for(int i = 0; i<n; i++){
        current_sum += arr[i];
        if(current_sum < 0){
            current_sum = 0;
        }
        max_so_far = max(current_sum, max_so_far);
    }
    return max_so_far;
}

// SPECIAL CASE: If array contains only negative numbers, need to output smallest negative number



int main(){
    int arr[] = {-3,2,5,-1,6,3,-2,7,-5,2};
    //int arr[] = {-3,-2,-5,-1,-6,-3,-2,-7,-5,-2};
    int n = sizeof(arr)/sizeof(int);
    cout<<maxsum_opt(arr,n)<<endl;
    return 0;
}