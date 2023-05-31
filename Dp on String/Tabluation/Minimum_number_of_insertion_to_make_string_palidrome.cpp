#include<bits/stdc++.h>
using namespace std;

solve(string s1 , string s2 , int m , int n , vector<vector<int>> dp){

    // base case
	for(int i = 0; i <= m; i++) dp[i][0] = 0;
	for(int j = 0; j <= m; j++) dp[0][j] = 0;

		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){

				// movemnet
			    int pick = 0;

				if(s1[i] == s2[j]) pick = 1 + dp[i - 1][j - 1];

				int left = dp[i - 1][j];
				int right = dp[i][j - 1];

				int lf = max(left , right);

				dp[i][j] = max(pick , lf);
			}
		}

		return dp[m - 1][n - 1];

}

int helper(string s1 , string s2){


int m = s1.size();
int n = s1.size();

vector<vector<int>> dp(m + 1 , vector<int>(n + 1 , 0));

//helper -> find out the lcs of this string and substract the length of this lcs from original string
//helper -> LCS -> 3(ele); -> lcs - original string
//                          abs(3 - 6);

 return abs(solve(s1 , s2 , m , n , dp) - m);


}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif


   
string s1 = "helper";  // mam , mbm , mdm
string s2 = s1;

reverse(s1.begin() , s1.end());




 cout << "Test Cases: " << helper(s1 , s2) << endl;

}




