#include<bits/stdc++.h>
using namespace std;

int solve(int n , vector<int> &dp){

	// base case
    int prev1 = 1;
    int prev2 = 1;
    int curr;

    for(int i = 2; i < n + 1; i++){

    	int left = prev1;

	    int right;

		if(i > 1){
		  right = prev2;

		}

         curr = left + right;
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