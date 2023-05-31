#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> coins , int index , int T ,vector<vector<int>> dp){

	// base conditions
	if(index == 0){
		if(T % coins[0] == 0){

			return 1;
		}

		return 0;
	}

	if(dp[index][T] != -1) return dp[index][T];

	//movement 

    int notPick = 0 + solve(coins , index - 1 , T , dp);

    int pick = 0;

    if(coins[index] <= T){

    	pick = solve(coins , index , T - coins[index] , dp);
    }

    return dp[index][T] = pick + notPick;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> coins{1,2,3};
  int n = coins.size();
  int T = 4;

vector<vector<int>> dp(n + 1 , vector<int> (T + 1 , -1));
 cout << "Test Cases: " << solve(coins , n - 1, T , dp) << endl;


}