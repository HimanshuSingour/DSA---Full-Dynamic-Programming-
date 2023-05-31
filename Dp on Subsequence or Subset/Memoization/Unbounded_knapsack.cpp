#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> val , vector<int> wt , int W , int index , vector<vector<int>>& dp){

	// base case
	if(index == 0){
       
       // if we are in index 0 the we need to think in different ways
		// like, if the target is 12 and the last elemt is 4 so , for sure we can pick 4 ( 3 times )
		// original W / value of weight at 1st index
		return W / wt[0];
	}

	if(dp[index][W] != -1) return dp[index][W];

	//Movement
	int notPick = 0 + solve(val , wt , W , index - 1 , dp);
	int pick = INT_MIN;

	if(W >= wt[index]){

		pick = val[index] + solve(val , wt , W - wt[index] , index - 1 , dp);
	}

	return dp[index][W] = max(pick , notPick);

}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> val{15, 20, 50}; 
  vector<int> wt{1, 2, 3};
  int W = 5;

  int n = val.size();

  vector<vector<int>> dp(n + 1 , vector<int> (W + 1 , -1));


 cout << "Test Cases: " << solve(val, wt , W , n - 1 , dp) << endl;


}