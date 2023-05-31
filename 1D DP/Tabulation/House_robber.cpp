#include<bits/stdc++.h>
using namespace std;


// Find The Maximum Of no Two Adjecent
int solve(vector<int> & arr , int index ,  vector<int> &dp){

	// base case
	dp[0] = arr[0];

   for(int i = 1; i < index + 1; i++){

   	int notPick = 0 + dp[i - 1];

   	int Pick = arr[i];

   	if(i > 1){

   	    Pick += dp[i - 2];
   	}
   
     dp[i] = max(Pick , notPick);
   }

   return dp[index];
    
    
}


int helper(int arr[] , int n){

	vector<int> temp1 , temp2;
    vector<int> dp(n + 1 , 0);

    for(int i = 0; i < n; i++){

    	if(i != 0) temp1.push_back(arr[i]);
    	if(i != n - 1) temp2.push_back(arr[i]);
    }



    int ans1 = solve(temp1 , temp1.size() - 1 , dp);
    int ans2 = solve(temp2 , temp2.size() - 1 , dp);

    return max(ans1 , ans2);

}



int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

    int arr[] = {5,5,10,100,10,5};
    int n = sizeof(arr) / sizeof(int);

   	cout << "Test Case :" << helper(arr , n);



}