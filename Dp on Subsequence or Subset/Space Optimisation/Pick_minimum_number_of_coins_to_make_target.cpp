#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> coins , int index , int T , vector<vector<int>> &dp){

	vector<int> prev(T + 1 , 0);
	vector<int> curr(T + 1 , 0);

	// base conditions
	for(int i = 0; i <= T; i++){

		if(i % coins[0] == 0){

			prev[i] = i / coins[0];
		}
		else{

		   prev[i] = 1e9;
  		}
	}

   for(int i = 1; i < index; i++){

   	  for(int j = 0; j <= T; j++){

   	  	//movement 
	    int notPick = 0 + prev[j];

	    int pick = 1e9;

	    if(coins[i] <= j){

	    	pick = 1 + curr[j - coins[i]];
	    }

	     curr[j] = min(notPick , pick);

   	  }

   	  prev = curr;
   }

   return prev[T];
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> coins{1,2,5};
  int n = coins.size();
  int T = 11;

  vector<vector<int>> dp(n + 1 , vector<int> (T + 1 , 0));


 cout << "Test Cases: " << solve(coins , n, T , dp) << endl;


}