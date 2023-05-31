#include<bits/stdc++.h>
using namespace std;

int solve(string s1 , string s2 , int n , int m , vector<vector<int>> & dp){

	// base case

	vector<int> prev(m + 1 , 0) , curr(m + 1 , 0);

   for(int i = 0; i <= n; i++) curr[0] = i;
   for(int j = 0; j <= m; j++) prev[j] = j;

    // Movement

    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){

	    	// if they match
			if(s1[i - 1] == s2[j - 1]){
		        
		       curr[j] = 0 + prev[j - 1];  
			}

			else{

			    // not match insert , delet , replace

				int d = 1 + prev[j]; // delet 
				int in = 1 + curr[j - 1]; // insert
				int r = 1 + prev[j - 1]; // replace
			    
			     curr[j] = min(d , min(in , r));

			}
    	}

    	prev = curr;
    }

    return curr[m];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

//length of string - LCS = ans

string s1 = "horse"; // 4 - 2 = 2 
string s2 = "ros"; // 3 - 2 = 1

int n = s1.size();
int m = s2.size();

vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , 0));

 
cout << "Test Cases: " << solve(s1 , s2 , n , m , dp) << endl;


}