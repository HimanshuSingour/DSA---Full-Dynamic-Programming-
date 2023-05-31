#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &arr , int target , int index , vector<vector<int>> dp){
    

    vector<int> prev(target + 1 , 0);
    vector<int> curr(target + 1 , 0);

	//base case
    prev[0] = curr[0] = true;

    prev[arr[0]] = true;

   
   for(int ind = 1; ind < index + 1; ind++){

   	   for(int t = 1; t <= target; t++){

		   	// Momement
			bool notPick = prev[t];

			bool pick = false;
		    
		    // if any element in an array smaller than t then i will pick otherwise not
			if(t >= arr[ind]){
				pick = prev[t - arr[ind]];

			}

		   curr[t] = notPick | pick;
   	   }

   	   prev = curr;
   }

   return prev[target];
	
}

bool util(vector<int> & arr , int n){
  
   int sum = 0;

   for(int i = 0; i < n; i++){
   	  sum = sum + arr[i];
   }


   vector<vector<int>> dp(n + 1 , vector<int> ((sum / 2) + 1 , -1));

   if(sum % 2 != 0) return false;
   else if(sum % 2 == 0) return solve(arr , sum / 2 , n - 1 , dp);
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