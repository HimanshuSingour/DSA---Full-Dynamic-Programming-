#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>> arr , int days , int prevTast , vector<vector<int>>& dp){

	//base case
	if(days == 0){
		int maxi = INT_MIN;
		for(int i = 0; i <= 2; i++){
			if(i != prevTast){
				maxi = max(maxi , arr[days][i]);
			}
		}

		return maxi;
	}

	if(dp[days][prevTast] != -1) return dp[days][prevTast];


	//Movement
    int maxi = INT_MIN;
    for(int i = 0; i <= 2; i++){
    	if(i != prevTast){
    		int points = arr[days][i] + solve(arr , days - 1 , i , dp);
    		maxi = max(maxi , points);
    	}
    }

    return dp[days][prevTast] = maxi;
}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

  vector<vector<int>> arr {{10 , 40 , 70},
                          {20 , 50 , 80}, 
                          {30 , 60 , 90}};

   
   int n = arr.size();

 vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , -1));
 cout << "Test Case :" << solve(arr , n - 1 , n , dp);



}