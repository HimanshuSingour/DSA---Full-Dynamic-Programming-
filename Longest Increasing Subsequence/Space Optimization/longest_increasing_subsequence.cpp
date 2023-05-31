#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int n , int index , int prev_index , vector<vector<int>>& dp){

	vector<int> next(n + 1, 0) , curr(n + 1 , 0);

	// base case
	for(int i = n - 1; i >= 0; i--){
		for(int j = i - 1; j >= -1; j--){    

			//not Take case
			int notTake = 0 + next[j + 1];
		    
		    //taking case
		    int take = 0;
		  	
		 	if(j == -1 || arr[i] > arr[j]){

		 		take = 1 + next[i + 1];
		 	}

		 	 curr[j + 1] = max(take , notTake);
		}

		next = curr;
	}

	return next[0];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<int> arr{10,9,2,5,3,7,101,18}; 
int n = arr.size();

vector<vector<int>> dp(n + 1 , vector<int>(n + 1, 0));

cout << "Test Cases: " << solve(arr , n , 0 , -1 , dp) << endl;


}