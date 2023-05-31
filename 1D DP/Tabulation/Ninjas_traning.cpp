#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>> arr , int days , int prevTast , vector<vector<int>>& dp){

	//base case

	// days 0, 0 task -> take maximum of two excuting that task
    dp[0][0] = max(arr[0][1] , arr[0][2]);

    // days 0, 1 task -> take maximum of two excuting that task
    dp[0][1] = max(arr[0][0] , arr[0][2]);

    // days 0, 2 task -> take maximum of two excuting that task
    dp[0][2] = max(arr[0][0] , arr[0][1]);

    //Take all the taks becze we dont have last
    dp[0][3] = max(arr[0][1] , max(arr[0][1] , arr[0][2]));


	// MOvements
	// 0 has done with base case that why we start from 1
	for(int d = 1; d < prevTast; d++){ //For Every Days

		for(int l = 0; l < 4; l++){ // There is Different tasks

			int maxi = INT_MIN;

		    for(int t = 0; t <= 2; t++){

		    	if(t != l){

		    		int points = arr[d][t] + dp[d - 1][t];
		    		maxi = max(maxi , points);
		    	}
		    }

		    dp[d][l] = maxi;

		}

	}

    return dp[prevTast - 1][prevTast];
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

 vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , 0));
 cout << "Test Case :" << solve(arr , n - 1 , n , dp);



}