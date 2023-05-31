#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int n , int index , int prev_index){

	// base case
	if(index == n) return 0;

	// movement
 
	//not Take case
	int notTake = 0 + solve(arr , n , index + 1 , prev_index);
    
    //taking case

    int take = 0;
  	
 	if(prev_index == -1 || arr[index] > arr[prev_index]){

 		take = 1 + solve(arr , n , index + 1 , index);
 	}

 	return max(take , notTake);

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<int> arr{10,9,2,5,3,7,101,18}; 
int n = arr.size();

cout << "Test Cases: " << solve(arr , n , 0 , -1) << endl;


}