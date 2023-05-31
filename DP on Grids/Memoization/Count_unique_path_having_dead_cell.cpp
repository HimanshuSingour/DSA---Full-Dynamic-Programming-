#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>>& grid , int row , int col , vector<vector<int>>& dp){
    
    // base case 
    if(row >= 0 && col >= 0 && grid[row][col] == -1) return 0;

	if(row == 0 && col == 0) return 1;
	if(row < 0 || col < 0) return 0;

	if(dp[row][col] != -1) return dp[row][col];

  // movement

	int down = solve(grid , row - 1 , col , dp);
	int righ = solve(grid , row , col - 1 , dp);

	return dp[row][col] = down + righ;

}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif


   	vector<vector<int>> grid {{0 , 0 , 0 }, 
   	                          {0 , -1 , 0},
   	                          {0 , 0 , 0 }};

   int n = grid.size();
   int m = grid[0].size();

   vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , -1));

   	cout << "Test Cases: " << solve(grid , n - 1, m - 1 , dp) << endl;


}