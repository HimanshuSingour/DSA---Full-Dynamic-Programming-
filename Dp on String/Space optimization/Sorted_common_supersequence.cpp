#include<bits/stdc++.h>
using namespace std;
int LCS(string s1 , string s2 , int m , int n , vector<vector<int>> dp){

	vector<int> curr(m + 1 , 0) , prev(n + 1 , 0);
   
   // base case
	for(int i = 0; i <= m; i++) curr[0] = 0;
	for(int j = 0; j <= n; j++) prev[j] = 0;

		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){

			    //movement
				int match = INT_MIN;

				if(s1[i - 1] == s2[j - 1]){

					match = 1 + prev[j - 1];
				}

				int left = prev[j];
				int right = curr[j - 1];

				int NotMatch = max(left , right);

				curr[j] = max(match , NotMatch);

			}
			
			prev = curr;

		}

	return curr[n];

}

int solve(string s1 , string s2 , int m , int n){

	vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));
   
   // finding the Longest common sequence
   int Lcs = LCS(s1 , s2 , m , n , dp);

   // adding both string len
   int Tls = m + n;

   return Tls - Lcs; 
 
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

//length of string - LCS = ans

string s1 = "AGGTAB"; // 4 - 2 = 2 
string s2 = "GXTXAYB"; // 3 - 2 = 1

int m = s1.size();
int n = s2.size();

 
cout << "Test Cases: " << solve(s1 , s2 , m , n) << endl;


}