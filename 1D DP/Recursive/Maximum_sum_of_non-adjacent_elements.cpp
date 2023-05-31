#include<bits/stdc++.h>
using namespace std;

int solve(int arr[] , int index){

	// base case
	if(index == 0) return arr[index];
	if(index < 0) return 0;

    int notPick = 0 + solve(arr , index - 1);
    int Pick = arr[index] + solve(arr , index - 2);


    return max(Pick , notPick);
  

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