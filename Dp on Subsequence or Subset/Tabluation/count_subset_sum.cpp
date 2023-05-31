#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> &arr , int target , int index , vector<vector<int>> &dp){

	//base case
	for(int i = 0; i < index + 1; i++){
		dp[i][0] = 1;
	}

	dp[0][arr[0]] = 1;

	for(int ind = 1; ind < index + 1; ind++){

		for(int t = 1; t <= target; t++){

		// Momement
		int notPick = dp[ind - 1][t];

		int pick = 0;
	    
	    // if any element in an array smaller than t then i will pick otherwise not
		if(t >= arr[ind]){
			pick = dp[ind - 1][t - arr[ind]];

		}
		
          dp[ind][t] = notPick + pick;

		}
	}

	return dp[index - 1][target];

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> arr{1 , 2 , 2 , 3};                     
  int n = arr.size();
  int target = 3;

vector<vector<int>> dp(n + 1 , vector<int>(target + 1 , 0));
 cout << "Test Cases: " << solve(arr , target , n , dp) << endl;


}