#include<bits/stdc++.h>
using namespace std;

int solve(int index , int arr[] , int k){

	// base case
	if(index == 0) return 0;

	int mini = INT_MAX; 
    
    int jump;

	for(int i = 1; i <= k; i++){
       
       if(index - i >= 0){
         
        jump = solve(index - i , arr , k) + abs(arr[index] - arr[index - i]); 
        mini = min(mini , jump);

       }	
	}
	
	return mini;
}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

    int arr[] = {10 , 30 , 40 , 50 , 20};
    int n = 5;
    int k = 3;


   	cout << "Test Case :" << solve(n - 1 , arr , k);


}