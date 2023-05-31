#include<bits/stdc++.h>
using namespace std;

int solve(int arr[] , int index , vector<int> & dp){

	// base case
	if(index == 0) return arr[index];
	if(index < 0) return 0;

	if(dp[index] != -1) return dp[index];
    
	// Lets Not pick the elements from array and move back
    int notPick = 0 + solve(arr , index - 1 , dp);

	//lets pick the element and move back - 2
    int Pick = arr[index] + solve(arr , index - 2 , dp);


    return dp[index] = max(Pick , notPick);
  

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