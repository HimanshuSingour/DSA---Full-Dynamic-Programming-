#include<bits/stdc++.h>
using namespace std;

int solve(string s1 , string s2 , int m , int n){

   // base case
	// on future call the strings goes -1 thats why,
	if(m < 0 || n < 0) return 0;

    //Movement
    int pick = INT_MIN;
    
    // if the character matches, then we can count 1 and move both m and n back
	if(s1[m] == s2[n]){

		pick = 1 + solve(s1 , s2 , m - 1 , n - 1);
	}
   
    // Not pick

    // if character are not matches then the we can move m back onace and n  back once
	int left = solve(s1 , s2 , m - 1 , n);
	int right = solve(s1 , s2 , m , n - 1);
    
    // take the max of both the strings
	int notPick = max(left , right);

	return max(pick , notPick);

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif


   
string s1 = "AGGTAB";
string s2 = "XAYB";

int m = s1.size();
int n = s2.size();

 cout << "Test Cases: " << solve(s1 , s2 , m - 1 , n - 1) << endl;


}