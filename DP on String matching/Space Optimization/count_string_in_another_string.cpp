#include<bits/stdc++.h>
using namespace std;
int solve(string s1 , string s2 , int n , int m , vector<vector<int>> &dp){

	vector<int> prev(m + 1 , 0) , curr(m + 1 , 0);
	prev[0] = curr[0] = 1;
   
   // base case
	// we are doint +1 becz n and m are going to negative indexing 
	// for(int i = 0; i <= n; i++) dp[i][0] = 1;
	// for(int j = 1; j <= m; j++) dp[0][j] = 0;  

			for(int i = 1; i <= n; i++){

				for(int j = 1; j <= m; j++){

					// if they are matching
					if(s1[i - 1] == s2[j - 1]){

						int match = prev[j - 1];
						int anotherOcuurance = prev[j];

						curr[j] = match + anotherOcuurance;

					}
				     
				     // if not

					else{

						 curr[j] = prev[j];
			}

		}

		prev = curr;


	}

	return prev[m];
   
   
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

//length of string - LCS = ans

string s1 = "himhim"; // 4 - 2 = 2 
string s2 = "him"; // 3 - 2 = 1

int n = s1.size();
int m = s2.size();

vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));

 
cout << "Test Cases: " << solve(s1 , s2 , n , m , dp) << endl;


}s