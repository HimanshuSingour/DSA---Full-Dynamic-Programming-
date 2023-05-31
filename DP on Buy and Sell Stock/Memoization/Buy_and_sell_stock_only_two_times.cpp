#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int index, int buyTrue , int n , int k , vector<vector<vector<int>>> dp){

	//base case
	if(k == 0) return 0;
	if(index == n) return 0;

	if(dp[index][buyTrue][k] != -1) return dp[index][buyTrue][k];

	//movement
	int buy = 0;
	int sell = 0;

	if(buyTrue == 1){
  
      buy = max(-arr[index] + solve(arr , index + 1 , 0 , n , k , dp) , solve(arr , index + 1 , 1 , n , k - 1 , dp));
	}
	else{
;
	  buy = max(arr[index] + solve(arr , index + 1 , 1 , n , k - 1 , dp) , solve(arr , index + 1 , 0 , n , k , dp));

	}

	return dp[index][buyTrue][k] = buy;

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<int> arr{10 ,22 ,5, 75, 65 ,80}; 
int n = arr.size();
int buy = 1;
int k = 2;

vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>>(buy + 1 , vector<int>(k + 1 , -1)));
 
cout << "Test Cases: " << solve(arr , 0 , 1 , n , k , dp) << endl;


}