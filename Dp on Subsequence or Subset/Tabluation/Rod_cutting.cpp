#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices , int N , int index , vector<vector<int>>& dp){

	// base case
	for(int i = 0; i <= index; i++){

		dp[0][i] =  i * prices[0];
	}
    

    for(int n = 1; n < index; n++){

    	for(int l = 0; l <= index; l++){

		    // Movement
			int notPick = 0 + dp[n - 1][l];

			int pick = INT_MIN;
		    
		    //i + 1 = rodlenth
		    int rodLength = n + 1;
			if(rodLength <= l){
		                           // roadlength off
				pick = prices[n] + dp[n][l - rodLength];
			}

			 dp[n][l] = max(pick , notPick);
    	}
    }

    return dp[index - 1][index];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif


   
  vector<int> prices{2,5,7,8,10}; 
  int N = 8;

  int n = prices.size();

  vector<vector<int>> dp(N + 1 , vector<int> (N + 1 , 0));

 cout << "Test Cases: " << solve(prices, N , n , dp) << endl;


}