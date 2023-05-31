#include<bits/stdc++.h>
using namespace std;

int solve(int index , int arr[]){

	// base case
	if(index == 0) return 0;

	// movement
	int left = solve(index - 1 , arr) + abs(arr[index] - arr[index - 1]);

	int right = INT_MAX; 

	if(index > 1){

		right = solve(index - 2 , arr) + abs(arr[index] - arr[index - 2]); 
	}

	return min(left , right);
}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

    int arr[] = {10 , 20 , 30 , 10};
    int n = 0;


   	cout << "Test Case :" << solve(n - 1 , arr);


}