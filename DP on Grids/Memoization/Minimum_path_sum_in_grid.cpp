#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>>& grid , int row , int col , vector<vector<int>> & dp){
  

  // base case
	if(row == 0 && col == 0) return grid[row][col];
	if(row < 0 || col < 0) return 1e9; 

	if(dp[row][col] != -1) return dp[row][col];

  // movement
	int up = grid[row][col] + solve(grid , row - 1 , col , dp);
	int right = grid[row][col] + solve(grid , row , col - 1 , dp);

	return dp[row][col] = min(up , right);

}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
   	vector<vector<int>> grid {{1 , 3 , 1}, {1 , 5 , 1}, {4 , 2 , 1}};

   	int n = grid.size();
   	int m = grid[0].size();

   	vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , -1));

   	cout << "Test Cases: " << solve(grid , n - 1, m - 1 , dp) << endl;


}