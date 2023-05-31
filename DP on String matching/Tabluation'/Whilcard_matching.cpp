#include<bits/stdc++.h>
using namespace std;

// in string matching we have to convert 0 based indexing to 1 based indexing

int solve(string s1 , string s2 , int n , int m , vector<vector<int>>& dp){

	//base case
	dp[0][0] = 1;
	for(int j = 0; j <= m; j++) dp[0][j] = 0;

	for(int i = 0; i <= n; i++){

		for(int j = 1; j <= n; j++){
			if(s1[j] != '*') {

				dp[0][j] = 0;
			} 
		}

		dp[i][0] = 1;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){

			// movement
			if(s1[i - 1] == s2[j - 1] || s1[i - 1] == '?'){

				 dp[i][j] = dp[i - 1][j - 1];
			}
			else{

				if(s1[i - 1] == '*'){

					 dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				}

				else dp[i][j] = 0;
			}

		}
	}

	return dp[n][m];
	  
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

string s1 = "ab*cd";  
string s2 = "abdefcdas"; 

int n = s1.size();
int m = s2.size();

vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));

 
cout << "Test Cases: " << solve(s1 , s2 , n , m , dp) << endl;


}