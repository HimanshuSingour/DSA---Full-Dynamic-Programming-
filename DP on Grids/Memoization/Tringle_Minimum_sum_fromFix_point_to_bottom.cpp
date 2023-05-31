#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>>& triangle , int row , int col , int n , vector<vector<int>>& dp){
  
    // base case
	if(row == n - 1) return triangle[row][col];

	if(dp[row][col] != -1) return dp[row][col];
	
	// for bottom movement
	int bottom = triangle[row][col] + solve(triangle , row + 1, col , n , dp);

    // for top movement
	int diagonal = triangle[row][col] + solve(triangle , row + 1 , col + 1 , n , dp);

	return dp[row][col] = min(bottom , diagonal);  

}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
   	vector<vector<int>> triangle {{1},
                                {2,3},
                                {3,6,7},
                                {8,9,6,10}};
                            

   	int n = triangle.size();
   	int m = triangle[0].size();

   	vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , -1));

   	cout << "Test Cases: " << solve(triangle , 0, 0 , n , dp) << endl;


}