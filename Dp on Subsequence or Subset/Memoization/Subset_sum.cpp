#include<bits/stdc++.h>
using namespace std;


bool solve(vector<int> &arr , int target , int index ,  vector<vector<int>>& dp){

	//base case
	if(target == 0) return true;
	if(index == 0){
		if(arr[0] == target){
			return true;
		}

		return false;
	}

	if(dp[index][target] != -1) return dp[index][target];

	// Momement
	bool notPick = solve(arr , target , index - 1 , dp);

	bool pick = false;
    
    // if any element in an array smaller than target then i will pick otherwise not
	if(target >= arr[index]){
		pick = solve(arr , target - arr[index] , index - 1 , dp);

	}
	

	return dp[index][target] = notPick | pick;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> arr{3 , 34 , 4 , 12 , 5 , 2};                     
  int n = arr.size();
  int target = 4;


 vector<vector<int>> dp(n + 1 , vector<int>(target + 1 , -1));
 cout << "Test Cases: " << solve(arr , target , n - 1 , dp) << endl;


}