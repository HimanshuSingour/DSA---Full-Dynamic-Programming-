#include<bits/stdc++.h>
using namespace std;

int solve(int index , int arr[] , vector<int> & dp){

	// base case
	int prev = 0;
	int prev2 = 0;
	int curr;
   
   for(int i = 1; i < index + 1; i++){

   	int left = prev + abs(arr[i] - arr[i - 1]);

	int right = INT_MAX; 

	if(i > 1){

		right = prev2 + abs(arr[i] - arr[i - 2]); 
	}
     
    curr = min(left , right);

		prev2 = prev;
		prev = curr;


   }

   return prev;   // i == at last
                  // n - 1 will you your answer that we have require
                  // so return prev
}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

    int arr[] = {10 , 20 , 30 , 10};
    int n = 4;

    vector<int> dp(n + 1 , 0);

   	cout << "Test Case :" << solve(n - 1 , arr , dp);


}