#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int target , int index){

	//base case
	
	if(index == 0){

		if(target == 0 && arr[0] == 0) return 2;
		if(target == 0) return 1;
		if(arr[0] == target) return 1;
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

int util(vector<int> & arr , int n , int diff){

int tSum = 0;

for(int i = 0; i < n; i++){
	tSum = tSum + arr[i];
}

// tSum - diff non negative and alsways even 
if(tSum - diff < 0 || (tSum - diff) % 2) return 0;
return solve(arr , (tSum - diff) / 2 , n - 1);


}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> arr{3 , 2 , 2 , 5 , 1};
  int diff = 1;                     
  int n = arr.size();

 cout << "Test Cases: " << util(arr , n , diff) << endl;


}