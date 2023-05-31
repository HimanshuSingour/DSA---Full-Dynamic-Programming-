#include<bits/stdc++.h>
using namespace std;

solve(string s1 , string s2 , int i , int j){

  // basse case
	if(i < 0 || j < 0) return 0;

	// movemnet
    
    int pick = 0;

	if(s1[i] == s2[j]) pick = 1 + solve(s1 , s2 , i - 1, j - 1);

	int left = solve(s1 , s2 , i - 1 , j);
	int right = solve(s1 , s2 , i , j - 1);

	int lf = max(left , right);

	return max(pick , lf);

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif


   
string s1 = "helper";  // mam , mbm , mdm
string s2 = s1;

reverse(s1.begin() , s1.end());

int m = s1.size();
int n = s1.size();


 cout << "Test Cases: " << abs(solve(s1 , s2 , m - 1 , n - 1) - m) << endl;

}




