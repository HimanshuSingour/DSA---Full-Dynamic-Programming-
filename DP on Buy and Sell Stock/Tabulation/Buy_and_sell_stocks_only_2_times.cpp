#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int index, int buyTrue , int n , int k , vector<vector<vector<int>>> dp){

	//base case

	for(int ind = n - 1; ind >= 0; ind--){
		for(int b = 0; b <= 1; b++){
			for(int cap = 1; cap <= 2; cap++){

			//movement
			int buy = 0;
			int sell = 0;

			if(b == 1){
		  
		      buy = max(-arr[ind] + dp[ind + 1][0][cap] , dp[ind + 1][1][cap]);
			}
			else{

			  buy = max(arr[ind] + dp[ind + 1][1][cap - 1] , dp[ind + 1][0][cap]);

			}

			 dp[ind][b][cap] = buy;

			}
		}
	}

	return dp[0][1][2];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<int> arr{3,3,5,0,0,3,1,4}; 
int n = arr.size();
int buy = 1;
int k = 2;

vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>>(buy + 1 , vector<int>(k + 1 , 0)));
 
cout << "Test Cases: " << solve(arr , 0 , 1 , n , k , dp) << endl;


}