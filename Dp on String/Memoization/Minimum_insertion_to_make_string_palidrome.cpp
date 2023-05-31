#include<bits/stdc++.h>
using namespace std;

solve(string s1 , string s2 , int i , int j , vector<vector<int>> dp){

  // basse case
	if(i < 0 || j < 0) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	// movemnet
    
    int pick = 0;

	if(s1[i] == s2[j]) pick = 1 + solve(s1 , s2 , i - 1, j - 1 , dp);

	int left = solve(s1 , s2 , i - 1 , j , dp);
	int right = solve(s1 , s2 , i , j - 1 , dp);

	int lf = max(left , right);

	return dp[i][j] = max(pick , lf);

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif


   
string s1 = "helper";  // mam , mbm , mdm
string s2 = s1;

reverse(s1.begin() , s1.end());

int m = s1.size();
int n = s1.size();

vector<vector<int>> dp(m + 1 , vector<int>(n + 1 , -1));


 cout << "Test Cases: " << abs(solve(s1 , s2 , m - 1 , n - 1 , dp) - m) << endl;

}




