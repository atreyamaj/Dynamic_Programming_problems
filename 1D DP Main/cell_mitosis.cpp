/*
QUESTION: 

There is a cell in a container. Cell has to divide into n cells. 
Cell can divide in the following ways:

1. Double the number of cells present in the container.
2. Increase number of cells in the container by 1.
3. Decrease the number of cells in the container by 1.

Each step has a cost x, y, z respectively for steps 1,2,3.

Find the minimum cost to reach n.

Given: x <= y <= z <= 10^5
1 <= n <= 10^5

There if my target is 7, I can go to 8 and then decrease by 1
*/

#include<bits/stdc++.h>
using namespace std;

long long mitosis_bottomup(int n, int x, int y, int z){// Bottom-Up approach

    //If n is even, n+1 will be odd, thus going to n+1 then going back will cost more
    //There for n%2==0, we will NOT use way #3.

    //If n is odd, the above won't be in use, but we can't come from i/2 since n is odd.

    long long *dp = new long long [n+1];
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i<=n; i++){
        if(i%2 == 0){
            // Cases:
            // 1. Go to half the value then double with cost = x
            // 2. Go to one less than the value, then cost of adding 1 = y
            dp[i] = min(dp[i/2] + x, dp[i-1] + y); 
        }
        else{
            // Cases: 
            // 1. One less than the value then add 1 with cost = y
            // 2. Go to half the number of (value + 1), then double with cost x, then subtract 1 with cost z
            dp[i] = min(dp[i-1] + y, dp[(i+1)/2] + x + z);
        }
    }
    return dp[n];
}

int main(){
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    cout<<mitosis_bottomup(n,x,y,z)<<endl;
    return 0;
}
