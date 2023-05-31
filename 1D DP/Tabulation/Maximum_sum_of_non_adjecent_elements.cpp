#include<bits/stdc++.h>
using namespace std;

int solve(int arr[] , int index , vector<int> & dp){

	// base case
	dp[0] = arr[0];

    for(int i = 1; i < index + 1; i++){

	    int Pick = arr[i];

	    if(i > 1){

	       Pick += dp[i - 2];
	    }

	    int notPick = 0 + dp[i - 1];

	  dp[i] = max(Pick , notPick);

    }

    return dp[index];

}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

    int arr[] = {1 ,2 ,4};
    int n = sizeof(arr) / sizeof(int);

    vector<int> dp(n + 1 , -1);

   	cout << "Test Case :" << solve(arr , n - 1 , dp);


}