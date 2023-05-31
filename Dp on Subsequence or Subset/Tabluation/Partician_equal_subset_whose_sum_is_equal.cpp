#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &arr , int target , int index , vector<vector<int>> dp){

	//base case
	for(int i = 0; i < index + 1; i++){
		dp[i][0] = true;
	}

    dp[0][arr[0]] = true;

   
   for(int ind = 1; ind < index + 1; ind++){

   	   for(int t = 1; t <= target; t++){

		   	// Momement
			bool notPick = dp[ind - 1][t];

			bool pick = false;
		    
		    // if any element in an array smaller than t then i will pick otherwise not
			if(t >= arr[ind]){
				pick = dp[ind - 1][t - arr[ind]];

			}

		   dp[ind][t] = notPick | pick;
   	   }
   }

   return dp[index - 1][target];
	
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