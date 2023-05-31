#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>>& grid , int row , int col){
    
    // base case 
	// Out of bound or if it is a dead cell
    if(row >= 0 && col >= 0 && grid[row][col] == -1) return 0;
	
    //Destination
	if(row == 0 && col == 0) return 1;
	if(row < 0 || col < 0) return 0;

  // movement

	int down = solve(grid , row - 1 , col);
	int righ = solve(grid , row , col - 1);

	return down + righ;

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

   	cout << "Test Cases: " << solve(grid , n - 1, m - 1) << endl;


}