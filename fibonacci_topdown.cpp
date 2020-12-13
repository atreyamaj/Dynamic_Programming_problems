#include<iostream>
using namespace std;

// Fibonacci using Top-Down Approach

int fib(int n){
    if( n == 1 or n == 0) return n;
    int ans = fib(n - 1) + fib(n-2);
    return ans;
}
int main(){
    int x = fib(6);
    cout<< "Henlo";
    cout << x;
}