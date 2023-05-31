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

bool util(vector<int> & arr , int n){
  
   int sum = 0;

   for(int i = 0; i < n; i++) sum = sum + arr[i];

   if(sum % 2 != 0) return false;
   else if(sum % 2 == 0) return solve(arr , sum / 2 , n - 1 );
   else return 0;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> arr{1 , 3 , 5};                     
  int n = arr.size();


 cout << "Test Cases: " << util(arr , n) << endl;


}