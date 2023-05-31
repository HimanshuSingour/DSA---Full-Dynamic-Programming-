#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int n){

	vector<int> dp(n , 1);

	// 109 2  5  3   7  101 18
	// 1   1  1  1   1    1  1 DP array now lets update when the condition meeet

	int maxi = INT_MIN;

	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < i; j++){

			if(arr[i] > arr[j]){

				dp[i] = max(dp[i] , 1 + dp[j]); 
			}
		}

		maxi = max(maxi , dp[i]);
	}

	return maxi;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<int> arr{7,7,7,7,7,7,7}; 
int n = arr.size();


cout << "Test Cases: " << solve(arr , n) << endl;


}