#include<bits/stdc++.h>
using namespace std;

int solve(int index , int arr[] ,  vector<int>& dp){

	// base case
	if(index == 0) return 0;

	if(dp[index] != -1) return dp[index];

	// movement
	int left = solve(index - 1 , arr , dp) + abs(arr[index] - arr[index - 1]);

	int right = INT_MAX; 

	if(index > 1){

		right = solve(index - 2 , arr , dp) + abs(arr[index] - arr[index - 2]); 
	}

	return dp[index] = min(left , right);


}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

    int arr[] = {10 , 20 , 30 , 10};
    int n = 4;

    vector<int> dp(n + 1 , -1); 


   	cout << "Test Case :" << solve(n - 1 , arr , dp);


}