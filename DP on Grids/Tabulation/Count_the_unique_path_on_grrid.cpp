#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>>& grid , int row , int col , vector<vector<int>>& dp){
  
  
    // base case
	for(int i = 0; i < row; i++){

		for(int j = 0; j < col; j++){

			if(i == 0 && j == 0) dp[i][j] = 1;

			else{

				// movement
				int down = 0;
				int righ = 0;

				if(i > 0) down = dp[i - 1][j];
                    
				if(j > 0) righ = dp[i][j - 1];

				dp[i][j] = down + righ;
			}
		}
	}

	return dp[row - 1][col - 1];
}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif
    
    int n;
    int m;
    cin >> n >> m;

   	vector<vector<int>> grid(n , vector<int> (m , 0));

   	// Dp of Increased 
   	vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , 0));

   	cout << "Test Cases: " << solve(grid , n, m , dp) << endl;


}