#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int target , int index , vector<vector<int>> &dp){

    vector<int> prev(target + 1, 0);
    vector<int> curr(target + 1 , 0);
	//base case
	if(arr[0] == 0) prev[0] = 2;
	else prev[0] = 1;

	if( arr[0] != 0 && arr[0] <= target ) prev[arr[0]] = 1;  // 1 case -pick

	for(int i = 1; i < index; i++){

		for(int j = 0; j <= target; j++){

			// Momement
			int notPick = prev[j];

			int pick = 0;
		    
		    // if any element in an array smaller than j then i will pick otherwise not
			if(j >= arr[i]){
				pick = prev[j - arr[i]];

			}
			
			curr[j] = notPick + pick;
		}

		prev = curr;
	}

	return prev[target];
}

int util(vector<int> & arr , int n , int diff){

int tSum = 0;



for(int i = 0; i < n; i++){
	tSum = tSum + arr[i];
}

vector<vector<int>> dp(n + 1 , vector<int>(((tSum - diff) / 2) + 1 , 0));


// tSum - diff non negative and alsways even 
if(tSum - diff < 0 || (tSum - diff) % 2) return 0;
return solve(arr , (tSum - diff) / 2 , n , dp);


}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> arr{3 , 2 , 2 , 5 , 1};
  int diff = 5;                     
  int n = arr.size();

 cout << "Test Cases: " << util(arr , n , diff) << endl;


}