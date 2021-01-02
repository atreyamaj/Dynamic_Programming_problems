/*
QUESTION:

There are more girls than boys.
Each boy has a certain number of chocolates.
Each girl has a certain number of candies.

Need to pair boys with girls such that
The sum of absolute differences between the boy's chocolate and the girl's candy in a pair, is minimized.

It is okay if some girls are not paired with boys. Every boy must be paired with a girl.

Given : Num girls > Num boys.

M = num boys
N = num girls
*/

#include<bits/stdc++.h>
#include<cmath>
using namespace std;
#define ll long long

ll n,m, a[5005], b[5005], dp[5005][5005];

ll f(ll i, ll j){
    if(i == n){
        // All boys have been paired.
        return 0;
    }
    if(j == m){
        // We have rejected many girls, no other girls avvailable for boys.
        return INT_MAX;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int op1 = abs(a[i] - b[j]) + f(i+1, j+1); // Have accepted j'th girl
    int op2 = f(i, j+1); // Have rejected j'th girl

    return dp[i][j] = min(op1, op2);
}

int main(){
    return 0;
}
