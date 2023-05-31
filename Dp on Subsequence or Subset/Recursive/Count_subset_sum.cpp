#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> &arr , int target , int index){

	//base case
	if(target == 0) return 1;

	if(index == 0){
		if(arr[0] == target){
			return 1;
		}

		return 0;
	}

	// Momement
	int notPick = solve(arr , target , index - 1);

	int pick = 0;
    
    // if any element in an array smaller than target then i will pick otherwise not
	if(target >= arr[index]){
		pick = solve(arr , target - arr[index] , index - 1);

	}
	

	return notPick + pick;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> arr{1 , 2 , 2 , 3};                     
  int n = arr.size();
  int target = 3;

 cout << "Test Cases: " << solve(arr , target , n - 1) << endl;


}