#include<bits/stdc++.h>
using namespace std;

int solve(int n , vector<int> &dp){

	// base case
    if(n == 0) return 1;
    if(n == 1) return 1;

    if(dp[n] != -1) return dp[n];

	// Movemnet
	int left = solve(n - 1 , dp);

	int right;

	if(n > 1){
	  right = solve(n - 2 , dp);

	}

	return dp[n] = left + right;

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