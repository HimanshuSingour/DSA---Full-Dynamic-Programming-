#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> coins , int index , int T , vector<vector<int>> &dp){

	// base conditions
	for(int i = 0; i <= T; i++){

		if(i % coins[0] == 0){

			dp[0][i] = i / coins[0];
		}
		else{

		   dp[0][i] = 1e9;
  		}

	}


   for(int i = 1; i < index; i++){

   	  for(int j = 0; j <= T; j++){

   	  	//movement 
	    int notPick = 0 + dp[i - 1][j];

	    int pick = 1e9;

	    if(coins[i] <= j){

	    	pick = 1 + dp[i][j - coins[i]];
	    }

	     dp[i][j] = min(notPick , pick);

   	  }
   }

   return dp[index - 1][T];
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> coins{1,2,5};
  int n = coins.size();
  int T = 11;

  vector<vector<int>> dp(n + 1 , vector<int> (T + 1 , 0));


 cout << "Test Cases: " << solve(coins , n, T , dp) << endl;


}