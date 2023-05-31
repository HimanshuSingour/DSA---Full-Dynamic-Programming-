#include<bits/stdc++.h>
using namespace std;

int solve(string s1 , string s2 , int i , int j , vector<vector<int>> & dp){

	// base case
   
   if(i < 0) return j + 1;
   if(j < 0) return i + 1; 

   if(dp[i][j] != -1) return dp[i][j]; 
  // Movement

	// if they match
	if(s1[i] == s2[j]){
        
       return solve(s1 , s2 , i - 1 , j - 1 , dp);  
	}

	// not match insert , delet , replace
	int d = 1 + solve(s1 , s2 , i - 1 , j , dp); // delet 
	int in = 1 + solve(s1 , s2 , i , j - 1 , dp); // insert
	int r = 1 + solve(s1 , s2 , i - 1 , j - 1 , dp); // replace
    
	return dp[i][j] = min(d , min(in , r));

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

//length of string - LCS = ans

string s1 = "himanshu"; // 4 - 2 = 2 
string s2 = "himansha"; // 3 - 2 = 1

int n = s1.size();
int m = s2.size();

vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , -1));

 
cout << "Test Cases: " << solve(s1 , s2 , n - 1 , m - 1 , dp) << endl;


}