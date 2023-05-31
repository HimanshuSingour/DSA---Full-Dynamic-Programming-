#include<bits/stdc++.h>
using namespace std;

int solve(int n , vector<int> & dp){


    int prev2 = 0;
    int prev = 1; 
    int curr;


	for(int i = 2; i < n + 1; i++){

	 	curr = prev + prev2;

	 	prev2 = prev;
	    prev = curr;
	 }
  

	 return prev;

	
}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   	int n;
   	cin >> n;

   	vector<int> dp(n + 1 , -1);

   	cout << "Test Case :" << solve(n , dp);


}