# Stuart Spiegel
#Returns the maximum value that can be put in a knapsack of capacity W .
def knapSack(W , wt , val , n):

    # Base Case
    if n == 0 or W == 0 :
        return 0

    # If weight of the nth item is more than Knapsack of capacity
    # W, then this item cannot be included in the optimal solution
    if (wt[n-1] > W):
        return knapSack(W , wt , val , n-1)

    # return the maximum of two cases:
    # (1) nth item included
    # (2) not included
    else:
        return max(val[n-1] + knapSack(W-wt[n-1] , wt , val , n-1),
                    knapSack(W , wt , val , n-1))

    # val = [60, 100, 120]
    # wt = [10, 20, 30]
    # W = 50
    # n = len(val)
    # print knapSack(W , wt , val , n)

# Time improvement over the above algorithm which is O (2^n) since each subtree is evaluated twice.
# Returns the maximum value that can be put in a knapsack of capacity W
# using Dynamic Programming the time complexity of Knapsack 0-1 is reduced to O(n * W) where
# n is the number of items and W is the knapsack capacity.
def knapSackFaster(W, wt, val, n):
    Q = [[0 for x in range(W+1)] for x in range(n+1)]

    #Build a Lookup-Table (Q[][]) that saves values that have already been recursively evaluated once.
    #Build table K[][] in bottom up manner
    for i in range(n+1):
        for w in range(W+1):
            if i==0 or w==0:
                Q[i][w] = 0
            elif wt[i-1] <= w:
                Q[i][w] = max(val[i-1] + Q[i-1][w-wt[i-1]], Q[i-1][w])
            else:
                Q[i][w] = Q[i-1][w]

    return K[n][W]
