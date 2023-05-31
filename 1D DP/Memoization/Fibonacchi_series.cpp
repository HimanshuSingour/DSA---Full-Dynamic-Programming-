#include<bits/stdc++.h>
using namespace std;

int solve(int n , vector<int> & dp){

	if(n <= 1){
		return n;
	}

	if(dp[n] != -1) return dp[n];

	return dp[n] = solve(n - 1 , dp) + solve(n - 2 , dp);
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