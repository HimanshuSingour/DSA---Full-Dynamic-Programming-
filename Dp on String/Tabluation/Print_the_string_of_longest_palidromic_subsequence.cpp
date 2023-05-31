#include<bits/stdc++.h>
using namespace std;

string solve(string s1 , string s2 , int m , int n , vector<vector<int>> &dp){

   // base case
	// on future call the strings goes -1 thats why,

	for(int i = 0; i <= m; i++) dp[0][i] = 0;
	for(int j = 0; j <= n; j++) dp[j][0] = 0;

	for(int i = 1; i <= m; i++){

		for(int j = 1; j <= n; j++){

			//Movement
		    int pick = INT_MIN;
		    
		    // if the character matches, then we can count 1 and move both m and n back
			if(s1[i - 1] == s2[j - 1]){

				pick = 1 + dp[i - 1][j - 1];
			}
		   
		    // Not pick
		    // if character are not matches then the we can move i back onace and j  back once
			int left = dp[i - 1][j];
			int right = dp[i][j - 1];
		    
		    // take the max of both the strings
			int notPick = max(left , right);

			dp[i][j] = max(pick , notPick);
		}
	}  
    
    // backtracking

	int len = dp[m][n];
	string ans = "";

	for(int i = 0; i < len; i++){
		ans = ans + "$";
	}

	int i = n;
	int j = m;
	int index = len - 1;

	while(i > 0 && j > 0){

		if(s1[i - 1] == s2[j - 1]){
			ans[index] = s1[i - 1];
			index--;
			i--;
			j--;
		}
		else if(dp[i][j - 1] > dp[i - 1][j]){
			j--;
		}
		else{

			i--;
		}
	}

	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif


   
string s1 = "cbbd";

string s2 = s1;

reverse(s1.begin() , s1.end());

int m = s1.size();
int n = s2.size();

vector<vector<int>> dp(m + 1 , vector<int>(n + 1 , 0));

 cout << "Test Cases: " << solve(s1 , s2 , m , n , dp) << endl;


}