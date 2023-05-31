#include<bits/stdc++.h>
using namespace std;

int solve(string s1 , string s2 , int m , int n , vector<vector<int>> &dp){

    // base case
	// on future call the strings goes -1 thats why,
	for(int i = 0; i <= m; i++) dp[i][0] = 0;
	for(int i = 0; i <= n; i++) dp[0][i] = 0;
    int ans = 0;

	for(int i = 1; i <= m; i++){

		for(int j = 1; j <= n; j++){

		    // if the character matches, then we can count 1 and move both m and n back
			if(s1[i - 1] == s2[j - 1]){

				dp[i][j] = 1 + dp[i - 1][j - 1];
				ans = max(ans , dp[i][j]);
			}

			else{

				dp[i][j] = 0;

			}	
		}
	}

	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif


   
string s1 = "abcdxyz";
string s2 = "xyzabcd";

int m = s1.size();
int n = s2.size();

vector<vector<int>> dp(m + 1 , vector<int> (n + 1 , 0));

 cout << "Test Cases: " << solve(s1 , s2 , m , n , dp) << endl;


}