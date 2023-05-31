#include<bits/stdc++.h>
using namespace std;

int solve(int n , vector<int> &dp){

	// base case
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i < n + 1; i++){

    	int left = dp[i - 1];

	    int right;

		if(i > 1){
		  right = dp[i - 2];

		}

         dp[n] = left + right;
    }

	return dp[n];
}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   	int n;
   	cin >> n;

   	vector<int> dp(n + 1 , -1);

   	cout << "Test Case :" << solve(n , dp);


}