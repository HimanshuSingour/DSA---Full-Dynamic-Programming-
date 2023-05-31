#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>>& grid , int row , int col , vector<vector<int>> & dp){
  
  // base case

	vector<int> prev(row + 1 , 0);

	for(int i = 0; i < row; i++){

		  vector<int> curr(row + 1 , 0);
		for(int j = 0; j < col; j++){

			if(i == 0 && j == 0) curr[j] = grid[i][j];
			else{

			// movement

		    int up = 0;
		    int right = 0;

		    if(i > 0) up = grid[i][j] + prev[j];
		    else up = 1e9;

		    if(j > 0) right = grid[i][j] +curr[j - 1];
		    else right = 1e9;

		     curr[j] = min(up , right);

			}
		}

		prev = curr;
	}

	return prev[col - 1];
}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
   	vector<vector<int>> grid {{1 , 3 , 1}, {1 , 5 , 1}, {4 , 2 , 1}};

   	int n = grid.size();
   	int m = grid[0].size();

   	vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));

   	cout << "Test Cases: " << solve(grid , n, m , dp) << endl;


}