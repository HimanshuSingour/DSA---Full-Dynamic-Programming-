#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int index, int buyTrue , int n , vector<vector<int>> &dp){

	//base case
	if(index == n) return 0;

	if(dp[index][buyTrue] != -1) return dp[index][buyTrue];

	//movement
	int buy = 0;
	int sell = 0;

	if(buyTrue == 1){
  
      buy = max(-arr[index] + solve(arr , index + 1 , 0 , n , dp) , solve(arr , index + 1 , 1 , n , dp));
	}
	else{
;
	  sell = max(arr[index] + solve(arr , index + 1 , 1 , n , dp) , solve(arr , index + 1 , 0 , n , dp));

	}

	return dp[index][buyTrue] = max(buy , sell);
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

vector<vector<int>> dp(n + 1 , vector<int>(buy + 1 , -1));
 
cout << "Test Cases: " << solve(arr , index , buy , n , dp) << endl;


}