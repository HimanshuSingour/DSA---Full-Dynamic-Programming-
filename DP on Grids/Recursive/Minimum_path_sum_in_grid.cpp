#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>>& grid , int row , int col){
  

  // base case
	if(row == 0 && col == 0) return grid[row][col];
	if(row < 0 || col < 0) return 1e9; // if this condition is true than we return very large value so that whenever 
	                                  // agin function call it will automaticall cancelled due to large value
  // movement
	int up = grid[row][col] + solve(grid , row - 1 , col);
	int right = grid[row][col] + solve(grid , row , col - 1);

	return min(up , right);

}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
   	vector<vector<int>> grid {{1 , 3 , 1}, {1 , 5 , 1}, {4 , 2 , 1}};

   	int n = grid.size();
   	int m = grid[0].size();

   	cout << "Test Cases: " << solve(grid , n - 1, m - 1) << endl;


}