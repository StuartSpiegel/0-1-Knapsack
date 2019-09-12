/*
Author: Stuart Spiegel
Date: 9/12/2019
***********************************************************************************************************************************************************
Given weights and values of n items, put these items in a knapsack of capacity W
to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1]
and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity,
find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
-->You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
***********************************************************************************************************************************************************
*/
//The item to be picked is either in the optimal set or it is not.
//Maximum value obtained by n-1 items and W weight (excluding nth item).
//Value of nth item plus maximum value obtained by n-1 items and W minus weight of the nth item (including nth item).

/* A Naive recursive implementation of 0-1 Knapsack problem */
#include <bits/stdc++.h>
using namespace std; //using the standard output

// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }

// Base Case, their are no items left to be picked
if (n == 0 || W == 0)
    return 0;

// If weight of the nth item is more
// than Knapsack capacity W, then
// this item cannot be included
// in the optimal solution
if (wt[n-1] > W)
    return knapSack(W, wt, val, n-1);

// Return the maximum of two cases:
// (1) nth item included
// (2) not included
else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1) );
}
// Main Driver Code
int main()
{
    int val[] = {80, 10, 50}; //the values of the respective items in the knapsack
    int wt[] = {10, 25, 40}; //the weights of the items
    int W = 100; //weight limit of knapSack
    int n = sizeof(val)/sizeof(val[0]); //number of items
    cout<<knapSack(W, wt, val, n); //print the output to the console
    return 0; //dummy return
}
