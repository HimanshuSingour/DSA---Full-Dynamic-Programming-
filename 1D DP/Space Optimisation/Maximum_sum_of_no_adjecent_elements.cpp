#include<bits/stdc++.h>
using namespace std;

int solve(int arr[] , int index ){

	// base case
	int prev = arr[0];
	int prev2 = 0;
	int curr = 0;

    for(int i = 1; i < index + 1; i++){

	    int Pick = arr[i];

	    if(i > 1){

	       Pick += prev2;
	    }

	    int notPick = 0 + prev;

	  curr = max(Pick , notPick);

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

    int arr[] = {1 ,2 ,4};
    int n = sizeof(arr) / sizeof(int);

   	cout << "Test Case :" << solve(arr , n - 1);


}