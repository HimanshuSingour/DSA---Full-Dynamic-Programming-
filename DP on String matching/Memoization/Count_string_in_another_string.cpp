#include<bits/stdc++.h>
using namespace std;
int solve(string s1 , string s2 , int i , int j , vector<vector<int>> &dp){
   
   // base case
	if(j < 0) return 1;
    if(i < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];


   // if they are matching
	if(s1[i] == s2[j]){

		int match = solve(s1 , s2 , i - 1 , j - 1 , dp);
		int anotherOcuurance = solve(s1 , s2 , i - 1 , j , dp);

		return dp[i][j] = match + anotherOcuurance;
	}
     
     // if not
	else{

		return dp[i][j] = solve(s1 , s2 , i - 1 , j , dp);
	}
   
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

//length of string - LCS = ans

string s1 = "babgbag"; // 4 - 2 = 2 
string s2 = "bag"; // 3 - 2 = 1

int n = s1.size();
int m = s2.size();

vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , -1));

 
cout << "Test Cases: " << solve(s1 , s2 , n - 1 , m - 1 , dp) << endl;


}