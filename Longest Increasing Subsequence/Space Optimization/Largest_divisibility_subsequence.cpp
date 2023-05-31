#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr , int n){

	vector<int> dp(n , 1);
	vector<int> hash(n);

	int maxi = INT_MIN;
	int lastIndex = 0;

	for(int i = 0; i < n; i++){

		hash[i] = i;
		for(int j = 0; j < i; j++){

			if(arr[i] % arr[j] == 0 && 1 + dp[j] > dp[i]){

				dp[i] = 1 + dp[j];
				hash[i] = j;
			}
		}

		if(dp[i] > maxi){
			maxi = dp[i];
			lastIndex = i;
		}
	}

	vector<int> ans;
	ans.push_back(arr[lastIndex]);

	while(hash[lastIndex] != lastIndex){
		lastIndex = hash[lastIndex];
		ans.push_back(arr[lastIndex]);
	}

	reverse(ans.begin() , ans.end());

	return ans;

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<int> arr{1,2,4,8}; 
int n = arr.size();


// cout << "Test Cases: " << solve(arr , n) << endl;

vector<int> ans = solve(arr , n);
for(auto i : ans){
	cout << i << " ";
}

cout << endl;

}