/*
QUESTION:

Given a brick wall of NxM, and tiles of size 1xM, you have to find out the total number of ways to arrange tiles on the wall
*/

#include <iostream>
#include<climits>
#include<cmath>
using namespace std;

int tiles(int n, int m, int dp[]){
    if(n<=m){
        return 1;
    }

    if(dp[n]!= 0) return dp[n];
    
    int ans;
    ans = tiles(n-1,m,dp) + tiles(n - m,m,dp);
    int mods = pow(10,9) + 9; 
    ans = ans % mods;
    return dp[n] = ans;
}

int main(){
    int t,n,m;
    cin>>t;
    for(int i = 0; i<t; i++){
        int dp[100001] = {0};
        cin>>n>>m;
        cout<<tiles(n,m, dp)<<endl;
    }

}