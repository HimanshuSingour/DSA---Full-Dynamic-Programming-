#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> value , vector<int> weight , int W , int index , vector<vector<int>> &dp){

	// base conditions
    for(int i = weight[0]; i <= W; i++){

    	dp[0][i] = value[0];
    }
    

    for(int i = 1; i < index; i++){
    	for(int j = 0; j <= W; j++){

    	// movements
		int notPick = 0 + dp[i - 1][j];

	    int pick = INT_MIN;
	    
	    // always check if the element that has been taking is always lesser than My bag
		if(weight[i] <= j){
	        
	        // if we pick the element, i have to reduce my bag j and go for next elemt
			pick = value[i] + dp[i - 1][j - weight[i]];
		}


		 dp[i][j] = max(notPick , pick);

    	}
    }

    return dp[index - 1][W];

}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> value{1 , 2 , 3};
  vector<int> weight{4 , 5 , 6};
  int n = value.size();
  int W = 3; 

  vector<vector<int>> dp(n + 1 , vector<int>(W + 1 , 0));                    

 cout << "Test Cases: " << solve(value , weight , W , n , dp) << endl;


}