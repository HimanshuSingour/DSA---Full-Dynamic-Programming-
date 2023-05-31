#include<bits/stdc++.h>
using namespace std;

int solve(string s1 , string s2 , int i , int j){

	// base case
   
   if(i < 0) return j + 1;
   if(j < 0) return i + 1; 

	// Movement

	// if they match
	if(s1[i] == s2[j]){
        
       return solve(s1 , s2 , i - 1 , j - 1);  
	}

	// not match insert , delet , replace
	int d = 1 + solve(s1 , s2 , i - 1 , j); // delet 
	int in = 1 + solve(s1 , s2 , i , j - 1); // insert
	int r = 1 + solve(s1 , s2 , i - 1 , j - 1); // replace
    
	return min(d , min(in , r));

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

//length of string - LCS = ans

string s1 = "himanshu"; // 4 - 2 = 2 
string s2 = "himansha"; // 3 - 2 = 1

int n = s1.size();
int m = s2.size();

 
cout << "Test Cases: " << solve(s1 , s2 , n - 1 , m - 1) << endl;


}