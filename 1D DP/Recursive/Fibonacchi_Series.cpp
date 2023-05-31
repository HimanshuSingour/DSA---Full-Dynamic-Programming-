#include<bits/stdc++.h>
using namespace std;

int solve(int n){

	if(n <= 1){
		return n;
	}

	return solve(n - 1) + solve(n - 2);
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