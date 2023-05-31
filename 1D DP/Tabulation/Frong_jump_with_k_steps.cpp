#include<bits/stdc++.h>
using namespace std;

int solve(int index , int arr[] , int k , vector<int> & dp){

	// base case
	dp[0] = 0;

	for(int j = 1; j < index + 1; j++){

		int mini = INT_MAX; 
	    
	    int jump;

		for(int i = 1; i <= k; i++){
	       
	       if(index - i >= 0){
	          
		        jump = dp[index - k] + abs(arr[index] - arr[index - k]); 
		        mini = min(mini , jump);

	       }	
		}
		
		return dp[index] = mini;
	}
	
}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

    int arr[] = {30,10,60 , 10 , 60 , 50};
    int n = sizeof(arr) / sizeof(int);
    int k = 2;

  vector<int> dp(n + 1 , 0);


   	cout << "Test Case :" << solve(n - 1 , arr , k , dp);


}