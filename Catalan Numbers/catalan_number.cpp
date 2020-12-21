/*
QUESTION:

Count number of BSTs (Binary Search Trees) that can be formed using N nodes numbered from 1,2,3,4,.....,n
*/

/*
#include<iostream>
#include<climits>
using namespace std;

int soln(int n, int dp[]){
    int N = n;
	if(n == 0 or n == 1){
        return 1;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans = 0;
    ans = ans + soln(n-1,dp)*soln(N-n-1,dp);
    return dp[n] = ans;
}

int main() {
	//int n;
	//cin>>n;
	int dp[101] = {0};
	cout<<soln(10,dp);
}


*/




#include<iostream>
#include<climits>
using namespace std;

int soln(int n, long long int dp[]){
    //Base
    if(n<=1) return 1;
    //Lookup
    if(dp[n]!=0){
        return dp[n];
    }

    long long int ans = 0;
    for(int i = 1; i<=n;i++){
        ans +=  soln(i-1,dp)*soln(n-i,dp);
    }
    return dp[n] = ans;
}

int main() {
	int n;
	cin>>n;
	long long int dp[101] = {0};
	cout<<soln(n,dp)<<endl;
}
