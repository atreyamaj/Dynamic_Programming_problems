/*
QUESTION:

Given n friends, each one can remain single or can be paired up with some other friend. 
Each friend can be paired only once. 
Find out the total number of ways in which friends can remain single or can be paired up.

Sample
Input: 3
Output: 4

Explanation:
{1}, {2}, {3} : all single 
{1}, {2,3} : 2 and 3 paired but 1 is single. 
{1,2}, {3} : 1 and 2 are paired but 3 is single.
 {1,3}, {2} : 1 and 3 are paired but 2 is single.
 Note that {1,2} and {2,1} are considered same.
*/

#include<iostream>
using namespace std;


int meet(int n, int dp[]){// MY OWN CODE TOPDOWN - CORRECT
    if(n==1 or n==2) return n;
    if(dp[n]!= 0 ) return dp[n];
    return dp[n] = meet(n-1, dp) + (n-1)*meet(n-2,dp);
}

long long countFriendsPairings(int n){ //cODING BLOCKS- BOTTOM UP
    long long dp[n+1];
    // Filling dp[] in bottom-up manner using
    // recursive formula explained above.
    for (int i=0; i<=n; i++)
    {
        if (i <= 2)
        dp[i] = i;
        else
        dp[i] = dp[i-1] + (i-1) * dp[i-2];
    }
    return dp[n];
}

int main() {
    int dp[31] = {0};
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        cout<<meet(n,dp)<<endl;
    }
    
}



