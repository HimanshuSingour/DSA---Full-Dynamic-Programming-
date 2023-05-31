#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int index, int buyTrue , int n , vector<vector<int>> &dp){

	//base case

	dp[n][0] = dp[n][1] = 0;

	for(int ind =  n - 1; ind >= 0; ind--){

		for(int b = 0; b <= 1; b++){

		//movement
		int buy = 0;
		int sell = 0;

		if(b == 1){
	  
	      buy = max(-arr[ind] + dp[ind + 1][0] , dp[ind + 1][1]);
		}

		else{
	
		  buy = max(arr[ind] + dp[ind + 1][1] , dp[ind + 1][0]);

		}

		
		dp[ind][b] = buy;


		}
	}

	return dp[index][buyTrue];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<int> arr{1,2,3,4,5}; 
int n = arr.size();

int index = 0;
int buy = 1;

vector<vector<int>> dp(n + 1 , vector<int>(buy + 1 , 0));
 
cout << "Test Cases: " << solve(arr , index , buy , n , dp) << endl;


}