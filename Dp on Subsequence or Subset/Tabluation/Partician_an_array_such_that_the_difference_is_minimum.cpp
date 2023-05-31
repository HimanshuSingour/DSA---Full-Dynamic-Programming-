#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int index){

	 // Taking array Total Sum
	int tSum = 0;
	for(int i = 0; i < index; i++){
	 	tSum = tSum + arr[i];
	}

	vector<vector<int>> dp(index + 1 , vector<int>(tSum + 1 , 0));

   // base cases
	for(int i = 0; i < index; i++){
		  dp[i][0] = true;
	}

	dp[0][arr[0]] = true;

	for(int ind = 1; ind < index; ind++){

		for(int t = 1; t < tSum; t++){

			// Momement
			bool notPick = dp[ind - 1][t];

			bool pick = false;
		    
		    // if any element in an array smaller than t then i will pick otherwise not
			if(t >= arr[ind]){
				pick = dp[ind - 1][t - arr[ind]];

			}
			

			dp[ind][t] = notPick | pick;

		}
	}

// calculation for minimum difference
int s1 = 0;
int s2 = 0;

int mini = 1e9;


// now we can check in dp table if the i having subset then we need it
for(int i = 0; i < tSum; i++){

	if(dp[index - 1][i] == true){
       
       s1 = i;
       s2 = tSum - i;

       int diff = abs(s1 - s2);

       mini = min(mini , diff);
	}
}
   

   return mini;
	
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> arr{10, 20, 15, 5, 25};                     
  int n = arr.size();

 cout << "Test Cases: " << solve(arr , n) << endl;


}