//
//  DynamicProgramming.cpp
//  CTCI
//
//  Created by Xuewen on 10/14/17.
//  Copyright © 2017 Xuewen. All rights reserved.
//

//Dynamic Programming is an algorithmic paradigm that solves a given complex problem by breaking it into subproblems and stores the results of subproblems to avoid computing the same results again.
//Two main properties of a problem that suggest that the given problem can be solved using Dynamic programming:
//1) Overlapping Subproblems
//2) Optimal Substructure
//Optimal Substructure: A given problems has Optimal Substructure Property if optimal solution of the given problem can be obtained by using optimal solutions of its subproblems.
//
//For example, the Shortest Path problem has following optimal substructure property:
//If a node x lies in the shortest path from a source node u to destination node v then the shortest path from u to v is combination of shortest path from u to x and shortest path from x to v. The standard All Pair Shortest Path algorithms like Floyd–Warshall and Bellman–Ford are typical examples of Dynamic Programming.
//
//On the other hand, the Longest Path problem doesn’t have the Optimal Substructure property. Here by Longest Path we mean longest simple path (path without cycle) between two nodes. Consider the following unweighted graph given in the CLRS book. There are two longest paths from q to t: q→r→t and q→s→t. Unlike shortest paths, these longest paths do not have the optimal substructure property. For example, the longest path q→r→t is not a combination of longest path from q to r and longest path from r to t, because the longest path from q to r is q→s→t→r and the longest path from r to t is r→q→s→t.
#include "DynamicProgramming.hpp"
#define NIL -1
#define MAX 100

DP::DP(){}
DP::~DP(){}

int DP::binomialCoeff(int n, int k) {
    if (k == 0)
        return 1;
    if (n == k)
        return 1;
    return binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k);
}

//Tabulation (Bottom Up)
int DP::binomialCoeffDP(int n, int k) {
    int array[n+1][k+1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= std::min(i,k); j++) {
            if (j == 0 || i == j)
                array[i][j] = 1;
            else
                array[i][j] = array[i-1][j-1] + array[i-1][j];
        }
    return array[n][k];
}

//Time Complexity: O(n*k)
//Auxiliary Space: O(k)
//
//Explanation:
//1==========>> n = 0, C(0,0) = 1
//1–1========>> n = 1, C(1,0) = 1, C(1,1) = 1
//1–2–1======>> n = 2, C(2,0) = 1, C(2,1) = 2, C(2,2) = 1
//1–3–3–1====>> n = 3, C(3,0) = 1, C(3,1) = 3, C(3,2) = 3, C(3,3)=1
//1–4–6–4–1==>> n = 4, C(4,0) = 1, C(4,1) = 4, C(4,2) = 6, C(4,3)=4, C(4,4)=1
//So here every loop on i, builds i’th row of pascal triangle, using (i-1)th row
//
//At any time, every element of array C will have some value (ZERO or more) and in next iteration, value for those elements comes from previous iteration.
//In statement,
//C[j] = C[j] + C[j-1]
//Right hand side represents the value coming from previous iteration (A row of Pascal’s triangle depends on previous row). Left Hand side represents the value of current iteration which will be obtained by this statement.
//
//Let's say we want to calculate C(4, 3),
//i.e. n=4, k=3:
//
//All elements of array C of size 4 (k+1) are
//initialized to ZERO.
//
//i.e. C[0] = C[1] = C[2] = C[3] = C[4] = 0;
//Then C[0] is set to 1
//
//For i = 1:
//C[1] = C[1] + C[0] = 0 + 1 = 1 ==>> C(1,1) = 1
//
//For i = 2:
//C[2] = C[2] + C[1] = 0 + 1 = 1 ==>> C(2,2) = 1
//C[1] = C[1] + C[0] = 1 + 1 = 2 ==>> C(2,1) = 2
//
//For i=3:
//C[3] = C[3] + C[2] = 0 + 1 = 1 ==>> C(3,3) = 1
//C[2] = C[2] + C[1] = 1 + 2 = 3 ==>> C(3,2) = 3
//C[1] = C[1] + C[0] = 2 + 1 = 3 ==>> C(3,1) = 3
//
//For i=4:
//C[4] = C[4] + C[3] = 0 + 1 = 1 ==>> C(4,4) = 1
//C[3] = C[3] + C[2] = 1 + 3 = 4 ==>> C(4,3) = 4
//C[2] = C[2] + C[1] = 3 + 3 = 6 ==>> C(4,2) = 6
//C[1] = C[1] + C[0] = 3 + 1 = 4 ==>> C(4,1) = 4
//
//C(4,3) = 4 is would be the answer in our example.
int DP::binomialCoeffDPMem(int n, int k) {
    int array[k+1];
    memset(array, 0, sizeof(array));
    array[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = std::min(i,k); j > 0; j--) {
            array[j] = array[j] + array[j-1];
        }
    return array[k];
}

//Memoization (Top Down): The memoized program for a problem is similar to the recursive version with a small modification that it looks into a lookup table before computing solutions. We initialize a lookup array with all initial values as NIL. Whenever we need solution to a subproblem, we first look into the lookup table. If the precomputed value is there then we return that value, otherwise we calculate the value and put the result in lookup table so that it can be reused later.
int DP::fiboTopDown(int n) {
    int lookup[MAX];
    memset(lookup, NIL, sizeof(lookup));
    if (n <= 1)
        lookup[n] = n;
    else {
        lookup[n] = fiboTopDown(n-1) + fiboTopDown(n-2);
    }
    return lookup[n];
}

int lishelper(int array[], int n, int *max_ref) {
    if (n == 1)
        return 1;
    int res, max_ending_here = 1;
    for (int i= 1; i < n; i++) {
        res = lishelper(array, i, max_ref);
        if (array[i-1] < array[n-1] && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;
    return max_ending_here;
}

int DP::lis(int array[], int n) {
    int max = 1;
    lishelper(array, n, &max);
    return max;
}

int DP::editDistance(std::string str1, std::string str2, int m, int n) {
    if (m == 0)
        return n;
    if (n ==0)
        return m;
    if (str1[m-1] == str2[n-1])
        return editDistance(str1, str2, m-1, n-1);
    return 1 + std::min({editDistance(str1, str2, m, n-1),  // insert
                        editDistance(str1, str2, m-1, n),  // remove
                        editDistance(str1, str2, m-1, n-1)});  // replace
}

int DP::editDistanceDP(std::string str1, std::string str2, int m, int n) {
    int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++) {
            // If first string is empty, only option is to
            // isnert all characters of second string
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            // If last character are different, consider all
            // possibilities and find minimum
            else
                dp[i][j] = 1 + std::min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
        }
    return dp[m][n];
}

//The time complexity of above solution is exponential, a close upper bound is O(3n). If we draw the complete recursion tree, we can observer that many subproblems are solved again and again. For example, when we start from n = 6, we can reach 4 by subtracting one 2 times and by subtracting 2 one times. So the subproblem for 4 is called twice
int DP::printCountRec(int dist) {
    if (dist < 0)
        return 0;
    if (dist == 0)
        return 1;
    else
        return printCountRec(dist-1) + printCountRec(dist-2) + printCountRec(dist-3);
}

int DP::printCountDP(int dist) {
    int dp[dist+1];
    dp[0] = 1;
    if (dist == 0)
        return dp[dist];
    dp[1] = 1;
    if (dist == 1)
        return dp[dist];
    dp[2] = 2;
    if (dist == 2)
        return dp[dist];
    if (dist > 2) {
        for (int i = 3; i <= dist; i++)
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[dist];
}

int DP::lcs(char *A, char *B, int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (A[m-1] == B[n-1])
        return 1 + lcs(A, B, m-1, n-1);
    return std::max(lcs(A, B, m-1, n), lcs(A, B, m, n-1));
}

int DP::lcs_dp(char *A, char *B, int m, int n) {
    int L[m+1][n+1];
    memset(L, 0, sizeof(L));
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++) {
            /* Following steps build L[m+1][n+1] in bottom up fashion. Note
             that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (A[i-1] == B[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else {
                L[i][j] = std::max(L[i-1][j], L[i][j-1]);
            }
        }
    return L[m][n];
}

//Shortest Common Supersequence
int DP::scs(char *A, char *B) {
    int m = int(strlen(A));
    int n = int(strlen(B));
    int l = lcs(A, B, m, n);
    return m + n - l;
}

// recursive method
int DP::scs_rec(char *A, char *B, int m, int n) {
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (A[m-1] == B[n-1])
        return 1 + scs_rec(A, B, m-1, n-1);
    return std::min(scs_rec(A, B, m-1, n), scs_rec(A, B, m, n-1));
}

// dp method
int DP::scs_dp(char *A, char *B, int m, int n) {
    int L[m+1][n+1];
    memset(L, 0, sizeof(L));
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                L[i][j] = j;
            else if (j == 0)
                L[i][j] = i;
            else if (A[i-1] == B[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = 1 + std::min(L[i-1][j], L[i][j-1]);
        }
    return L[m][n];
}




