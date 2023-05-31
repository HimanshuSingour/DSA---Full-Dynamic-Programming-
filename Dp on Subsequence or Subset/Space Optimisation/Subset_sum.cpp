#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &arr , int k , int n ,  vector<vector<bool>>& dp){
  
     vector<bool> prev(k + 1 , 0);
     vector<bool> curr(k + 1 , 0);

	//base case
	prev[0] = true;
	curr[0] = true;

	prev[arr[0]] = true;

	for(int ind = 1; ind < n; ind++){

		for(int target = 1; target <= k; target++){

			// Momement
				bool notPick = prev[target];

				bool pick = false;
			    
			    // if any element in an array smaller than target then it will pick otherwise not
				if(target >= arr[ind]){
					pick = prev[target - arr[ind]];

			}


			curr[target] = pick | notPick;
			    
		}

		prev = curr;
	}
   
   //it will return the same
	return prev[k];

}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> arr{1,2,3,4};                     
  int n = arr.size();
  int target = 8;


 vector<vector<bool>> dp(n + 1 , vector<bool>(target + 1 , 0));

 cout << "Test Cases: " << solve(arr , target , n , dp) << endl;


}