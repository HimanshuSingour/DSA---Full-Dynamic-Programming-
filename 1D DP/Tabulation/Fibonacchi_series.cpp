#include<bits/stdc++.h>
using namespace std;

int solve(int n , vector<int> & dp){

   // Base case to initilization
    dp[0] = 0;
    dp[1] = 1; 

	for(int i = 2; i < n + 1; i++){

	 	dp[i] = dp[i - 1] + dp[i - 2];
	 }    
	 
    // return the last block
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