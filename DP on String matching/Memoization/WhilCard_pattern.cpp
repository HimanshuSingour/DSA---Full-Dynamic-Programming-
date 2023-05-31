#include<bits/stdc++.h>
using namespace std;

bool solve(string s1 , string s2 , int n , int m , vector<vector<int>>& dp){

	//base case
	if(n < 0 && m < 0) return true;
	if(n < 0 && m >= 0) return false;
	if(n >= 0 && m < 0) {

		for(int i = 0; i < n; i++){
			if(s1[i] != '*') {

				return false;
			}

		}

		return true;
	}

	if(dp[n][m] != -1) return dp[n][m];

	// movement
	if(s1[n] == s2[m] || s1[n] == '?'){

		return dp[n][m] = solve(s1 , s2 , n - 1 , m - 1 , dp);
	}
	else{

		if(s1[n] == '*'){

			return dp[n][m] = solve(s1 , s2 , n - 1 , m , dp) || solve(s1 , s2 , n , m - 1 , dp);
		}

		else return dp[n][m] = false;
	}

	  
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

string s1 = "abc*d";  
string s2 = "abdefghijkld"; 

int n = s1.size();
int m = s2.size();

vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , -1));

 
cout << "Test Cases: " << solve(s1 , s2 , n - 1 , m - 1 , dp) << endl;


}