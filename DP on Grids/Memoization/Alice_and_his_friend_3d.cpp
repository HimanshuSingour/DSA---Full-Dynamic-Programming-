#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>> &grid , int row , int col1 , int col2 , int n ,int m, vector<vector<vector<int>>> &dp){

	// base case

	//out of bound 
	if(col1 < 0 || col2 < 0 || col1 >= m || col2 >= m) return -1e9;
    
    //destinations
    if(row == n - 1){
        // if they lie on the same box
    	if(col1 == col2){
    		return grid[row][col1];
    	}
       // if they lie on the differe box
    	return grid[row][col1] + grid[row][col2];
    }
    
    if(dp[row][col1][col2] != -1) return dp[row][col1][col2];

    // Moment
    int maxi = INT_MIN;

    // for 1 alice movement, bob have three movement , or vice versa
    for(int d1 = -1; d1 <= +1; d1++){
    	for(int d2 = -1; d2 <= +1; d2++){

           int ans = 0;

           //if they lie in the same box so, we can count one once
           if(col1 == col2){
              
              ans = grid[row][col1] + solve(grid , row + 1 , col1 + d1 , col2 + d2 , n , m , dp);
           }
           	  // else we can count both
           	  ans = grid[row][col1] + grid[row][col2] + solve(grid , row + 1 , col1 + d1 , col2 + d2 , n , m , dp);

           maxi = max(maxi , ans);
    	}
    }

    return dp[row][col1][col2] = maxi;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
   	vector<vector<int>> grid{ {3 , 7},
                              {7 , 6}};
                           
  int n = grid.size();
  int m = grid[0].size();

  vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>>(m + 1 , vector<int>(m , -1)));

 cout << "Test Cases: " << solve(grid , 0 , 0 ,  m - 1 , n ,  m , dp) << endl;


}