#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int n){

	vector<int> dp(n , 1);
	vector<int> hash(n);

	int maxi = INT_MIN;
	int lastIndex = 0;

	for(int i = 0; i < n; i++){
		   hash[i] = i;

		for(int j=  0; j < i; j++){
			if(arr[i] > arr[j] && 1 + dp[j] > dp[i]){

				dp[i] = 1 + dp[j];
				hash[i] = j;

			}
		}

		if(dp[i] > maxi){
			maxi = dp[i];
			lastIndex = i;
		}
	}
    
    // backtracking of LIS
    vector<int> ans;
    ans.push_back(arr[lastIndex]);
    
    while(hash[lastIndex] != lastIndex){

    	lastIndex = hash[lastIndex];
    	ans.push_back(arr[lastIndex]);
    }

    // reverse it for better
    reverse(ans.begin() , ans.end());

    // output
    for(auto i : ans){
    	cout << i << " ";
    }

    cout << endl;
    
    // return length of LIS
    return maxi;


}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<int> arr{1 , 3 , 5 , 4 , 7}; 
int n = arr.size();


cout << "Test Cases: " << solve(arr , n) << endl;


}