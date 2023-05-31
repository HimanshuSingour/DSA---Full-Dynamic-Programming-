#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int index, int buyTrue , int n , vector<vector<int>>& dp){

	// if the base case having all 0s, it is not mendotary to write base case in tabulation

	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j <= 1; j++){

	    //movement
		int buy = 0;
		int sell = 0;

		if(j == 1){
	  
	      buy = max(-arr[i] + dp[i + 1][0] , dp[i + 1][1]);
		}
		else{
	
		  buy = max(arr[i] + dp[i + 2][1] , dp[i + 1][0]);

		}

		dp[i][j] = buy;


		}
	}

	return dp[index][buyTrue];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<int> arr{4, 5, 2, 10, 1 ,15}; 
int n = arr.size();
int buyTrue = 1;

vector<vector<int>> dp(n + n , vector<int>(buyTrue + 1 , 0));
 
cout << "Test Cases: " << solve(arr , 0 , 1 , n , dp) << endl;


}