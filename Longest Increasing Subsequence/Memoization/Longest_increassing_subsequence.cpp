#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int n , int index , int prev_index , vector<vector<int>>& dp){

	// base case
	if(index == n) return 0;

	if(dp[index][prev_index + 1] != -1) return dp[index][prev_index + 1];

	// movement
 
	//not Take case
	int notTake = 0 + solve(arr , n , index + 1 , prev_index , dp);
    
    //taking case

    int take = 0;
  	
 	if(prev_index == -1 || arr[index] > arr[prev_index]){

 		take = 1 + solve(arr , n , index + 1 , index , dp);
 	}

 	return dp[index][prev_index] = max(take , notTake);

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<int> arr{3, 10, 2, 1, 20}; 
int n = arr.size();

vector<vector<int>> dp(n + 1 , vector<int>(n + 1, -1));

cout << "Test Cases: " << solve(arr , n , 0 , -1 , dp) << endl;


}