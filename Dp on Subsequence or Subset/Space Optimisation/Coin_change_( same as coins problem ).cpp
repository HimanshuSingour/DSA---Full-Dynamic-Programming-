#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> coins , int index , int T ,vector<vector<int>> dp){
   

   vector<int> prev(T + 1 , 0);
   vector<int> curr(T + 1 , 0);


	// base conditions
	for(int i = 0; i <= T; i++){

		if(i % coins[0] == 0) prev[i] = 1;

		else prev[i] = 0;
		
	}

	for(int i = 1; i < index; i++){

		for(int j = 0; j <= T; j++){

			//movement 
		    int notPick = prev[j];

		    int pick = 0;

		    if(coins[i] <= j){

		    	pick = curr[j - coins[i]];
		    }

		    curr[j] = pick + notPick;
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

   
  vector<int> coins{1,2,3};
  int n = coins.size();
  int T = 4;

vector<vector<int>> dp(n + 1 , vector<int> (T + 1 , 0));
 cout << "Test Cases: " << solve(coins , n, T , dp) << endl;


}