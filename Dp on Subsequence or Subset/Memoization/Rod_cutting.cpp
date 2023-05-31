#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices , int N , int index , vector<vector<int>>& dp){

	// base case
	if(index == 0){
		return N * prices[0];
	}

	if(dp[index][N] != -1) return dp[index][N];

	// Movement
	int notPick = 0 + solve(prices , N , index - 1 , dp);

	int pick = INT_MIN;
    
    //i + 1 = roadleangth
    int rodLength = index + 1;
	if(rodLength <= N){
                                         // roadlength off
		pick = prices[index] + solve(prices , N - rodLength , index , dp);
	}

	return dp[index][N] = max(pick , notPick);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif


   
  vector<int> prices{3, 5, 8, 9, 10, 17, 17}; 
  int N = 8;

  int n = prices.size();

  vector<vector<int>> dp(n + 1 , vector<int> (N + 1 , -1));

 cout << "Test Cases: " << solve(prices, N , n - 1 , dp) << endl;


}