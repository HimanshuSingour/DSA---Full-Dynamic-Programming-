#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> value , vector<int> weight , int W , int index , vector<vector<int>> &dp){

	// base conditions
    if(index == 0){
     
        // Now, there is single element, so check if that single elemnt fit in my beg or not
    	if(weight[0] <= W){
    		return value[0];
    	}
        
        //else 0
    	return 0;
    }
    
    if(dp[index][W] != -1) return dp[index][W];

	// movements
	int notPick = 0 + solve(value , weight , W , index - 1 , dp);

    int pick = INT_MIN;
    
    // always check if the element that has been taking is always lesser than My bag
	if(weight[index] <= W){
        
        // if we pick the element, i have to reduce my bag W and go for next elemt
		pick = value[index] + solve(value , weight , W - weight[index] , index - 1 , dp);
	}


	return dp[index][W] = max(notPick , pick);

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

  vector<vector<int>> dp(n + 1 , vector<int>(W + 1 , -1));                    

 cout << "Test Cases: " << solve(value , weight , W , n - 1 , dp) << endl;


}