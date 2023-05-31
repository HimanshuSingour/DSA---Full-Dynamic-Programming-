#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> coins , int index , int T , vector<vector<int>> &dp){

	// base conditions

	if(index == 0){
		if(T % coins[0] == 0){

			return T / coins[0];
		}

		return 1e9;
	}

	if(dp[index][T] != -1) return dp[index][T];

	//movement 

    int notPick = 0 + solve(coins , index - 1 , T , dp);

    int pick = 1e9;

    if(coins[index] <= T){

    	pick = 1 + solve(coins , index , T - coins[index] , dp);
    }

    return dp[index][T] = min(notPick , pick);
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> coins{1,2,5};
  int n = coins.size();
  int T = 11;
  vector<vector<int>> dp(n + 1 , vector<int> (T + 1 , -1));


 cout << "Test Cases: " << solve(coins , n - 1, T , dp) << endl;


}