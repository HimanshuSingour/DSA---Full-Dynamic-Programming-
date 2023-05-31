#include<bits/stdc++.h>
using namespace std;

int solve(string s1 , string s2 , int m , int n , vector<vector<int>> &dp){

   // base case
	// on future call the strings goes -1 thats why,
	if(m < 0 || n < 0) return 0;

	if(dp[m][n] != -1) return dp[m][n];

    //Movement
    int pick = INT_MIN;
    
    // if the character matches, then we can count 1 and move both m and n back
	if(s1[m] == s2[n]){

		pick = 1 + solve(s1 , s2 , m - 1 , n - 1 , dp);
	}
   
    // Not pick

    // if character are not matches then the we can move m back onace and n  back once
	int left = solve(s1 , s2 , m - 1 , n , dp);
	int right = solve(s1 , s2 , m , n - 1 , dp);
    
    // take the max of both the strings
	int notPick = max(left , right);

	return dp[m][n] = max(pick , notPick);

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif


   
string s1 = "abcde";
string s2 = "abcde";

int m = s1.size();
int n = s2.size();

vector<vector<int>> dp(m + 1 , vector<int> (n + 1 , -1));

 cout << "Test Cases: " << solve(s1 , s2 , m - 1 , n - 1 , dp) << endl;


}