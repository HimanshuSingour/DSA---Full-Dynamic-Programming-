#include<bits/stdc++.h>
using namespace std;

/*

time complexity : o(N X M)
reason : there is 2 nested loops

space complexity : o(N + M)

*/

int solve(string s1 , string s2 , int m , int n , vector<vector<int>> &dp){

    // base case
	// on future call the strings goes -1 thats why,
	for(int i = 0; i <= m; i++) dp[i][0] = 0;
	for(int i = 0; i <= n; i++) dp[0][i] = 0;

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


   // if matches in DP array move Diagonal
   // if notMatches in Dp array move the max of both ((i , j - 1)(i - 1 , j)) 
   // backtracking
    int len = dp[m][n];

	string s = "";
	for(int i = 0; i < len; i++){
		s = s + "$";
	}

	int i = m;
	int j = n;
	int index = len - 1;

	while(i > 0 && j > 0){

		if(s1[i - 1] == s2[j - 1]){
			s[index] = s1[i - 1];
			index--;
			i--;
			j--;
		}
		else if(dp[i][j - 1] < dp[i - 1][j]){
			i--;
		}
		else {
			j--;
		}
	}

	cout << s << endl;
 }



int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif


   
string s1 = "abcde";
string s2 = "bdgek ";

int m = s1.size();
int n = s2.size();

vector<vector<int>> dp(m + 1 , vector<int> (n + 1 , 0));

cout << "Test Case : " << solve(s1 , s2 , m , n , dp);


}