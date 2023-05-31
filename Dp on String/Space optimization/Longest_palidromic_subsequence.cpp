#include<bits/stdc++.h>
using namespace std;

int solve(string s1 , string s2 , int m , int n , vector<vector<int>> &dp){

   // base case
	// on future call the strings goes -1 thats why,

	vector<int> curr(m + 1 , 0);
	vector<int> prev(m + 1 , 0);


	for(int i = 0; i <= m; i++) prev[i] = 0;
	for(int j = 0; j <= n; j++) curr[0] = 0;

	for(int i = 1; i <= m; i++){

		for(int j = 1; j <= n; j++){

			//Movement
		    int pick = INT_MIN;
		    
		    // if the character matches, then we can count 1 and move both m and n back
			if(s1[i] == s2[j]){

				pick = 1 + prev[j - 1];
			}
		   
		    // Not pick
		    // if character are not matches then the we can move i back onace and j  back once
			int left = prev[j];
			int right = curr[j - 1];
		    
		    // take the max of both the strings
			int notPick = max(left , right);

			curr[j] = max(pick , notPick);
		}

		prev = curr;
	}  

	return curr[n - 1];
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


}s