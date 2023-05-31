#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices , int N , int index , vector<vector<int>>& dp){

	vector<int> curr(index + 1 , 0);
	vector<int> prev(index + 1 , 0);


	// base case
	for(int i = 0; i <= index; i++){

		prev[i] =  i * prices[0];
	}
    

    for(int n = 1; n < index; n++){

    	for(int l = 0; l <= index; l++){

		    // Movement
			int notPick = 0 + prev[l];

			int pick = INT_MIN;
		    
		    //i + 1 = rodlenth
		    int rodLength = n + 1;
			if(rodLength <= l){
		                           // roadlength off
				pick = prices[n] + curr[l - rodLength];
			}

			 curr[l] = max(pick , notPick);
    	}

    	prev = curr;
    }

    return prev[index];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif


   
  vector<int> prices{2,5,7,8,10}; 
  int N = 8;

  int n = prices.size();

  vector<vector<int>> dp(N + 1 , vector<int> (N + 1 , 0));

 cout << "Test Cases: " << solve(prices, N , n , dp) << endl;


}