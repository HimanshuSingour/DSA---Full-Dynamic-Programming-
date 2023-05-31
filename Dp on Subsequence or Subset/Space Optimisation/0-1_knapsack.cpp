#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> value , vector<int> weight , int W , int index , vector<vector<int>> &dp){

	// base conditions

	vector<int> prev(W + 1 , 0);
	vector<int> curr(W + 1 , 0);

    for(int i = weight[0]; i <= W; i++){

    	prev[i] = value[0];
    }
    

    for(int i = 1; i < index; i++){
    	for(int j = 0; j <= W; j++){

    	// movements
		int notPick = 0 + prev[j];

	    int pick = INT_MIN;
	    
	    // always check if the element that has been taking is always lesser than My bag
		if(weight[i] <= j){
	        
	        // if we pick the element, i have to reduce my bag j and go for next elemt
			pick = value[i] + prev[j - weight[i]];
		}


		 curr[j] = max(notPick , pick);

    	}

    	prev = curr;
    }

    return prev[W];

}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> value{1 , 2 , 3};
  vector<int> weight{4 , 5 , 1};
  int n = value.size();
  int W = 4; 

  vector<vector<int>> dp(n + 1 , vector<int>(W + 1 , 0));                    

 cout << "Test Cases: " << solve(value , weight , W , n , dp) << endl;


}