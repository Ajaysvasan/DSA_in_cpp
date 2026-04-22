#include<bits/stdc++.h>
using namespace std;
// my approach
int dfs(int n,vector<vector<int>>& G1 , vector<vector<int>>& G2 , int S , int& currentSum , int row , int col , bool& isG2){
   if(row >= n || col >= n) return currentSum;
   if(row == n - 1 && col == n - 1){
     return currentSum + max({(isG2 ? max(G1[row][col] - S , G2[row][col]) : G1[row][col]) , (isG2 ? G2[row][col] : max(G1[row][col] - S , G2[row][col]))});
   }
    if(G1[row][col] > G2[row][col] && !isG2){
        currentSum += G1[row][col];
    }else if(G1[row][col] > G2[row][col] && isG2){
        if(G1[row][col] - S > G2[row][col]){
            currentSum += G1[row][col] - S;
            isG2 = false;
        }else{
            currentSum += G2[row][col];
        }
    }else if(G1[row][col] < G2[row][col] && isG2){
        currentSum += G2[row][col];
    }else{
        if(G2[row][col] - S > G1[row][col]){
            currentSum += G2[row][col] - S;
            isG2 = true;
        }else{
            currentSum += G1[row][col];
        }
    }
    int right = dfs(n , G1 , G2 , S , currentSum , row , col + 1 , isG2);
    int down = dfs(n , G1 , G2 , S , currentSum , row + 1 , col , isG2);
    return max(right , down);
}

int getMaximumValue(int n , vector<vector<int>>& G1 , vector<vector<int>>&G2 , int S){
    int currentSum = 0;
    bool isG2 = false;
    return dfs(n , G1 , G2 , S, currentSum  , 0, 0 , isG2);
}
// Correct approach using Dp
int n;
int S;

vector<vector<int>> G1, G2;

/*
dp[row][col][prevGrid]
prevGrid:
0 -> currently using G1
1 -> currently using G2
*/

vector<vector<vector<int>>> dp;

int solve(int row,int col,int prevGrid)
{
    if(row>=n || col>=n)
        return INT_MIN;

    if(dp[row][col][prevGrid]!=-1)
        return dp[row][col][prevGrid];

    int currentValue;

    if(prevGrid==0)
        currentValue=G1[row][col];
    else
        currentValue=G2[row][col];

    if(row==n-1 && col==n-1)
        return dp[row][col][prevGrid]=currentValue;

    int bestMove=INT_MIN;

    // Move right or down
    vector<pair<int,int>> dirs={
        {row,col+1},
        {row+1,col}
    };

    for(auto [nr,nc] : dirs)
    {
        if(nr<n && nc<n)
        {
            // stay in same grid
            bestMove=max(
                bestMove,
                solve(nr,nc,prevGrid)
            );

            // switch grid
            bestMove=max(
                bestMove,
                solve(nr,nc,1-prevGrid)-S
            );
        }
    }

    return dp[row][col][prevGrid]=currentValue+bestMove;
}

int getMaximumValue(
    int N,
    vector<vector<int>>& grid1,
    vector<vector<int>>& grid2,
    int penalty
)
{
    n=N;
    S=penalty;
    G1=grid1;
    G2=grid2;

    dp.assign(
        n,
        vector<vector<int>>(n,vector<int>(2,-1))
    );

    // Start in either grid
    return max(
        solve(0,0,0),
        solve(0,0,1)
    );
}