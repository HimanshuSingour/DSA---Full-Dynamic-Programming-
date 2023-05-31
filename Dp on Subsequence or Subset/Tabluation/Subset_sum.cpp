#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &arr , int k , int n ,  vector<vector<bool>>& dp){

	//base case
	for(int i = 0; i < n; i++) dp[i][0] = true;

	dp[0][arr[0]] = true;

	for(int ind = 1; ind < n; ind++){

		for(int target = 1; target <= k; target++){

			// Momement
				bool notPick = dp[ind - 1][target];

				bool pick = false;
			    
			    // if any element in an array smaller than target then it will pick otherwise not
				if(target >= arr[ind]){
					pick = dp[ind - 1][target - arr[ind]];

			}


			dp[ind][target] = pick | notPick;
			    
		}
	}
   
   //it will return the same
	return dp[n - 1][k];

}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> arr{1,2,3,4};                     
  int n = arr.size();
  int target = 3;


 vector<vector<bool>> dp(n + 1 , vector<bool>(target + 1 , 0));

 cout << "Test Cases: " << solve(arr , target , n , dp) << endl;



}