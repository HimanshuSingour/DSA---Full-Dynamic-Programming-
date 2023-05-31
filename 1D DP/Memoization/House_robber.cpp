#include<bits/stdc++.h>
using namespace std;


// Find The Maximum Of no Two Adjecent
int solve(vector<int> & arr , int index ,  vector<int> &dp){

	// base case
	if(index == 0) return arr[index];
	if(index < 0) return 0;

	if(dp[index] != -1) return dp[index];

    int notPick = 0 + solve(arr , index - 1 , dp);
    int Pick = arr[index] + solve(arr , index - 2 , dp);


    return dp[index] = max(Pick , notPick);

}


int helper(int arr[] , int n){

	vector<int> temp1 , temp2;
   
    vector<int> dp(n + 1 , -1);

/*

    1 , 2 , 3 , 4 , 5 , 6

    in temp1 = 1 2 3 4 5
    in temp2 = 2 3 4 5 6


    */ 

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

    int arr[] = {1,5,1,2,6};
    int n = sizeof(arr) / sizeof(int);

   	cout << "Test Case :" << helper(arr , n);



}