#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &arr , int target , int index , vector<vector<int>> dp){

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

bool util(vector<int> & arr , int n){
  
   int sum = 0;

   for(int i = 0; i < n; i++){
   	  sum = sum + arr[i];
   }


   vector<vector<int>> dp(n + 1 , vector<int> ((sum / 2) + 1 , -1));

   if(sum % 2 != 0) return false;
   else if(sum % 2 == 0) return solve(arr , sum / 2 , n - 1 , dp);
   else return 0;


}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> arr{1 , 3 , 5};                     
  int n = arr.size();


 cout << "Test Cases: " << util(arr , n) << endl;


}