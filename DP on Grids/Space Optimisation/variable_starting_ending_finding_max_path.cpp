#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>> &grid , int row , int col , int n , int m , vector<vector<int>> &dp){
 

    vector<int> curr(m + 1 , 0);
    vector<int> prev(m + 1 , 0);
	// base case
	for(int j = 0; j < m; j++){
		prev[j] = grid[0][j];
	}

	for(int i = 1; i < n; i++){ 

		for(int j = 0; j < m; j++){

	   // Movemnet
	    int up = grid[i][j] + prev[j];

	    int right = grid[i][j];
        
	    if(j - 1 >= 0) right += prev[j - 1];
	    else right += -1e9;

       
	    int left = grid[i][j]; 

	    if(j + 1 < m) left += prev[j + 1];
	    else left += -1e9;

	     curr[j] = max(up , max(right , left));

		}

		prev = curr;
	}
 
 int maxi = -1e9;

  for(int j = 0; j < m; j++){

  	  maxi = max(maxi , prev[j]);
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


 vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , 0));   

 cout << "Test Cases: " << solve(grid , n , m , n , m , dp) << endl;


}