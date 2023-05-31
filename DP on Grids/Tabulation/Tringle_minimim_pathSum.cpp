#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>>& triangle , int row , int col , int n , vector<vector<int>>& dp){
  
// opposite of recursion is tabulation


	// for i(row) there is 4 j(col) So, we have 4 base case to n - 1 
	for(int j = 0; j < n; j++){
		dp[n - 1][j] = triangle[n -1 ][j];
	}

	
	for(int i = n - 2; i >= 0; i--){
		for(int j = i; j >= 0; j--){

			int bottom = triangle[i][j] + dp[i + 1][j];
			int diagonal = triangle[i][j] + dp[i + 1][j + 1];

			dp[i][j] = min(bottom , diagonal); 
		}
	}

	return dp[0][0];
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

   	vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , 0));

   	cout << "Test Cases: " << solve(triangle , 0, 0 , n , dp) << endl;


}