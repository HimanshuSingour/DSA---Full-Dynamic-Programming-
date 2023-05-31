#include<bits/stdc++.h>
using namespace std;
// Distinct Subsequnce
int solve(string s1 , string s2 , int i , int j){
   
   // base case
	if(j < 0) return 1;
    if(i < 0) return 0;


   // if they are matching

	if(s1[i] == s2[j]){

		int match = solve(s1 , s2 , i - 1 , j - 1);
		int anotherOcuurance = solve(s1 , s2 , i - 1 , j);

		return match + anotherOcuurance;
	}

	else{

		return solve(s1 , s2 , i - 1 , j);
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

 
cout << "Test Cases: " << solve(s1 , s2 , n - 1 , m - 1) << endl;


}