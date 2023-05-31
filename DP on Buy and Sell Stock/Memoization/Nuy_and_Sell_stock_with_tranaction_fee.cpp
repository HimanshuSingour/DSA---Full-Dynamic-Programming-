#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int index, int buyTrue , int n , int fee , vector<vector<int>>& dp){

	//base case
	if(index == n) return 0;

	if(dp[index][buyTrue] != -1) return dp[index][buyTrue];

	//movement
	int buy = 0;
	int sell = 0;

	if(buyTrue == 1){
  
      buy = max(-arr[index] + solve(arr , index + 1 , 0 , n , fee , dp) , solve(arr , index + 1 , 1 , n , fee , dp));
	}
	else{
       // transactions always happen when the sell done
	  sell = max(arr[index] - fee + solve(arr , index + 1 , 1 , n , fee , dp) , solve(arr , index + 1 , 0 , n , fee , dp));

	}

	return dp[index][buyTrue] = max(buy , sell);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<int> arr{1,3,2,8,4,9}; 
int n = arr.size();
int fee = 2;

vector<vector<int>> dp(n + 1 , vector<int>(fee , -1));
 
cout << "Test Cases: " << solve(arr , 0 , 1 , n , fee , dp) << endl;


}