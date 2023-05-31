#include<bits/stdc++.h>
using namespace std;

int solve(int n){

	// base case
    if(n == 0) return 1;
    if(n == 1) return 1;

	// Movemnet
	int left = solve(n - 1);

	int right;

	if(n > 1){
	  right = solve(n - 2);

	}

	return left + right;
}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   	int n;
   	cin >> n;

   	cout << "Test Case :" << solve(n);


}