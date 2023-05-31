#include<bits/stdc++.h>
using namespace std;0

// you have to but and sell on single 


int solve(vector<int> & arr , int n){

	int profit = 0;
	int mini = arr[0];


	for(int i = 1; i < n; i++){

		int buy = arr[i] - mini;
		profit = max(profit , buy); // strore profies
		mini = min(mini , arr[i]); // make sure you have the track of minimum

	}

	return profit;  
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<int> arr{1 , 2  ,3 , 4 , 40 , 89}; 
int n = arr.size();
 
cout << "Test Cases: " << solve(arr , n) << endl;


}