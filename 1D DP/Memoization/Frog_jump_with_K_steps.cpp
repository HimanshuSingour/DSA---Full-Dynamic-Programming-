#include<bits/stdc++.h>
using namespace std;

int solve(int index , int arr[] , int k , vector<vector<int>> & dp){

	// base case
	if(index == 0) return 0;

	if(dp[index][k] != -1) return dp[index][k];

	int mini = INT_MAX; 
    
    int jump;

	for(int i = 1; i <= k; i++){
       
       if(index - i >= 0){
         
        jump = solve(index - i , arr , k , dp) + abs(arr[index] - arr[index - i]); 
        mini = min(mini , jump);

       }	
	}
	
	return dp[index][k] = mini;
}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

    int arr[] = {30,10,60 , 10 , 60 , 50};
    int n = sizeof(arr) / sizeof(int);
    int k = 2;

    vector<vector<int>> dp(n + 1 , vector<int> (k + 1 , -1));


   	cout << "Test Case :" << solve(n - 1 , arr , k , dp);


}