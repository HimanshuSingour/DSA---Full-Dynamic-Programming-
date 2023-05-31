#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> coins , int index , int T){

	// base conditions

	if(index == 0){
		if(T % coins[0] == 0){

			return T / coins[0];
		}

		return 1e9;
	}

	//movement 

    int notPick = 0 + solve(coins , index - 1 , T);

    int pick = 1e9;

    if(coins[index] <= T){

    	pick = 1 + solve(coins , index , T - coins[index]);
    }

    return min(notPick , pick);
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> coins{1,2,3};
  int n = coins.size();
  int T = 7;


 cout << "Test Cases: " << solve(coins , n - 1, T) << endl;


}