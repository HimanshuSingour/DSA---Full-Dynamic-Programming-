#include<bits/stdc++.h>
using namespace std;


bool solve(vector<int> &arr , int target , int index){

	//base case
	if(target == 0) return true;
	if(index == 0){
		if(arr[0] == target){
			return true;
		}

		return false;
	}

	// Momement
	bool notPick = solve(arr , target , index - 1);

	bool pick = false;
    
    // if any element in an array smaller than target then i will pick otherwise not
	if(target >= arr[index]){
		pick = solve(arr , target - arr[index] , index - 1);

	}
	

	return notPick | pick;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> arr{3 , 34 , 4 , 12 , 5 , 2};                     
  int n = arr.size();
  int target;
  cin >> target;


  
 cout << "Test Cases: " << solve(arr , target , n - 1) << endl;


}