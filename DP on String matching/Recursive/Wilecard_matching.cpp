#include<bits/stdc++.h>
using namespace std;

bool solve(string s1 , string s2 , int n , int m){

	//base case
	if(n < 0 && m < 0) return true;
	if(n < 0 && m >= 0) return false;
	if(n >= 0 && m < 0) {

		for(int i = 0; i < n; i++){
			if(s1[i] != '*') {

				return false;
			}

		}

		return true;
	}

	// movement
	if(s1[n] == s2[m] || s1[n] == '?'){

		return solve(s1 , s2 , n - 1 , m - 1);
	}
	else{

		if(s1[n] == '*'){

			return solve(s1 , s2 , n - 1 , m) || solve(s1 , s2 , n , m - 1);
		}

		else return false;
	}

	  
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

string s1 = "aa";  
string s2 = "aa"; 

int n = s1.size();
int m = s2.size();

 
cout << "Test Cases: " << solve(s1 , s2 , n - 1 , m - 1) << endl;


}