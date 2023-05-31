#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>> &grid , int row , int col , int n , int m , vector<vector<int>> &dp){

	// base case
    
    //out of bound 
    if(col < 0 || col >= m) return -1e9;

    // Destinations
	if(row == 0) return grid[0][col];

	if(dp[row][col] != -1) return dp[row][col];

    // Movemnet
    int up = grid[row][col] + solve(grid , row - 1 , col , n , m , dp);
    int right = grid[row][col] + solve(grid , row - 1 , col - 1 , n , m , dp);
    int lef = grid[row][col] + solve(grid , row - 1 , col + 1 , n , m , dp);

    return dp[row][col] = max(up , max(right , lef));

}

int util(vector<vector<int>> &grid){

  int n = grid.size();
  int m = grid[0].size();

 vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , -1));   

 int maxi = -1e9;

  for(int j = 0; j < m; j++){

  	  maxi = max(maxi , solve(grid , n - 1 , j , n , m , dp));
  }

  return maxi;


}
   

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
   	vector<vector<int>> grid{ {1, 2, 10 , 4},
                              {100 , 3 , 2 , 1},
                              {1 , 1 , 20 , 2},
                              {1 , 2 , 2 , 1}};
    


   	cout << "Test Cases: " << util(grid) << endl;


}