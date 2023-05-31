#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>> &grid , int row , int col , int n , int m , vector<vector<int>> &dp){

	// base case
	for(int j = 0; j < m; j++){
		dp[0][j] = grid[0][j];
	}

	for(int i = 1; i < n; i++){ 

		for(int j = 0; j < m; j++){

	   // Movemnet
	    int up = grid[i][j] + dp[i - 1][j];

	    int right = grid[i][j];
        
	    if(j - 1 >= 0) right += dp[i - 1][j - 1];
	    else right += -1e9;

       
	    int lef = grid[i][j]; 

	    if(j + 1 < m) lef += dp[i - 1][j + 1];
	    else lef += -1e9;

	     dp[i][j] = max(up , max(right , lef));

		}
	}
 
 int maxi = -1e9;

  for(int j = 0; j < m; j++){

  	  maxi = max(maxi , dp[n - 1][j]);
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

  int n = grid.size();
  int m = grid[0].size();


 vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , -1));   

 cout << "Test Cases: " << solve(grid , n , m , n , m , dp) << endl;


}