#include<bits/stdc++.h>
using namespace std;
int LCS(string s1 , string s2 , int i , int j){
   
   // base case
	if(i < 0 || j < 0) return 0;

	//movement
	int match = 0;

	if(s1[i] == s2[j]){

		match = 1 + LCS(s1 , s2 , i - 1 , j - 2);
	}

	int exclutingI = LCS(s1 , s2 , i - 1 , j);
	int includingI = LCS(s1 , s2 , i , j - 1);

	int NotMatch = max(exclutingI , includingI);

	return max(match , NotMatch);

}

int solve(string s1 , string s2 , int m , int n){
   
   int Lcs = LCS(s1 , s2 , m , n);
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