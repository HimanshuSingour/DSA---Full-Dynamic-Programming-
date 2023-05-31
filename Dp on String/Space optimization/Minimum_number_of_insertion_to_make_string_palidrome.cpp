#include<bits/stdc++.h>
using namespace std;

solve(string s1 , string s2 , int m , int n , vector<vector<int>> dp){

	vector<int> curr(m + 1 , 0);
	vector<int> prev(m + 1 , 0);


    // base case
	for(int i = 0; i <= m; i++) curr[0] = 0;
	for(int j = 0; j <= m; j++) prev[j] = 0;

		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){

				// movemnet
			    int pick = 0;

				if(s1[i - 1] == s2[j - 1]) pick = 1 + prev[j - 1];

				int left = prev[j];
				int right = curr[j - 1];

				int lf = max(left , right);

				curr[j] = max(pick , lf);
			}

			prev = curr;
		}

    return prev[n];
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


   
string s1 = "abcaa";  // mam , mbm , mdm
string s2 = s1;

reverse(s1.begin() , s1.end());




 cout << "Test Cases: " << helper(s1 , s2) << endl;

}




