#include<bits/stdc++.h>
using namespace std;

// in string matching we have to convert 0 based indexing to 1 based indexing

int solve(string s1 , string s2 , int n , int m , vector<vector<int>>& dp){

	vector<int> prev(m + 1 , 0) , curr(m + 1,  0);

	//base case
	prev[0] = 1;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){

			// movement
			if(s1[i - 1] == s2[j - 1] || s1[i - 1] == '?'){

				 curr[j] = prev[j - 1];
			}
			else{

				if(s1[i - 1] == '*'){

					 curr[j] = prev[j] || curr[j - 1];
				}

				else curr[j] = 0;
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

string s1 = "him?a";  
string s2 = "himta"; 

int n = s1.size();
int m = s2.size();

vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));

 
cout << "Test Cases: " << solve(s1 , s2 , n , m , dp) << endl;


}