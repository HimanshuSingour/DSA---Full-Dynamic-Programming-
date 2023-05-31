#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> val , vector<int> wt , int W , int index , vector<vector<int>>& dp){

	// base case

	// Think about changing parameters

	for(int i = 0; i <= W; i++){
		dp[0][i] = i / wt[0] * val[0];
	}

    // if we are in index 0 the we need to think in different ways
    // like, if the target is 12 and the last elemt is 4 so , for sure we can pick 4 ( 3 times )
	// original W / value of weight at 1st index

	for(int i = 1; i < index + 1; i++){

		for(int j = 0; j <= W; j++){

			//Movement
			int notPick = 0 + dp[i - 1][j];
			int pick = INT_MIN;

			if(j >= wt[i]){

				pick = val[i] + dp[i - 1][j - wt[i]];
			}

			dp[i][j] = max(pick , notPick);
		}
	}

	return dp[index - 1][W];
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> val{10, 40, 50, 70}; 
  vector<int> wt{1, 3, 4, 5};
  int W = 8;

  int n = val.size();

  vector<vector<int>> dp(n + 1 , vector<int> (W + 1 , 0));


 cout << "Test Cases: " << solve(val, wt , W , n , dp) << endl;


}