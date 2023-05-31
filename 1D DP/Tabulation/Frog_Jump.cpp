#include<bits/stdc++.h>
using namespace std;

int solve(int index , int arr[] , vector<int> & dp){

	// base case
	dp[0] = 0;
   
   for(int i = 1; i < index + 1; i++){

   	int left = dp[i - 1] + abs(arr[i] - arr[i - 1]);

	int right = INT_MAX; 

	if(i > 1){

		right = dp[i - 2] + abs(arr[i] - arr[i - 2]); 
	}

	dp[i] = min(left , right);


   }

   return dp[index - 1];
}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

    int arr[] = {10 , 20 , 30 , 10};
    int n = 4;

    vector<int> dp(n + 1 , 0);

   	cout << "Test Case :" << solve(n - 1 , arr , dp);


}