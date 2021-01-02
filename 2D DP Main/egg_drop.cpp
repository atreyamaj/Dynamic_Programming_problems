/*
QUESTION:

There is a building with N floors and you have K eggs.
There is a critical floor.

If you throw an egg from the critical floor or above, the egg will break. From below the critical floor, won't break.

Find the minimum number of attempts it will take to find the critical floor.
*/

#include<bits/stdc++.h>
using namespace std;

// Therefore, MINIMIZE total attempts to find critical floor in the worst case.
// So if you have only k = 1 egg, then the number of attempts at worst will be N, since need to drop from each.


//At floor X, if a thrown egg breaks, then number of floors left = x-1, eggs = k-1.
//If doesn't break, floors are from x to n ---> (n-x) floors, eggs = k.
//For worst case, take the max of the above two cases.
//Final ans will be = min of the above



/* Function to get minimum  
number of trials needed in worst  
case with n eggs and k floors */

int eggDrop(int n, int k) 
{ 
    /* A 2D table where entery  
    eggFloor[i][j] will represent  
    minimum number of trials needed for 
    i eggs and j floors. */
    int eggFloor[n + 1][k + 1]; 
    int res; 
    int i, j, x; 
  
    // We need one trial for one floor and 0 
    // trials for 0 floors 
    for (i = 1; i <= n; i++) { 
        eggFloor[i][1] = 1; 
        eggFloor[i][0] = 0; 
    } 
  
    // We always need j trials for one egg 
    // and j floors. 
    for (j = 1; j <= k; j++) 
        eggFloor[1][j] = j; 
  
    // Fill rest of the entries in table using 
    // optimal substructure property 
    for (i = 2; i <= n; i++) { 
        for (j = 2; j <= k; j++) { 
            eggFloor[i][j] = INT_MAX; 
            for (x = 1; x <= j; x++) { 
                res = 1 + max( 
                              eggFloor[i - 1][x - 1], 
                              eggFloor[i][j - x]); 
                if (res < eggFloor[i][j]) 
                    eggFloor[i][j] = res; 
            } 
        } 
    } 
  
    // eggFloor[n][k] holds the result 
    return eggFloor[n][k]; 
} 
  
/* Driver program to test to pront printDups*/
int main() 
{ 
    int n = 2, k = 36; 
    printf("\nMinimum number of trials "
           "in worst case with %d eggs and "
           "%d floors is %d \n", 
           n, k, eggDrop(n, k)); 
    return 0; 
} 