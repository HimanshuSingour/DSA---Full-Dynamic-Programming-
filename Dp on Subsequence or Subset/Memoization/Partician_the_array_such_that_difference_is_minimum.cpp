#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &arr , int target , int index ,  vector<vector<int>>& dp){

	//base case
	if(target == 0) return true;
	if(index == 0){
		if(arr[0] == target){
			return true;
		}

		return false;
	}

	if(dp[index][target] != -1) return dp[index][target];

	// Momement
	bool notPick = solve(arr , target , index - 1 , dp);

	bool pick = false;
    
    // if any element in an array smaller than target then i will pick otherwise not
	if(target >= arr[index]){
		pick = solve(arr , target - arr[index] , index - 1 , dp);

	}
	

	return dp[index][target] = notPick | pick;
}

int Utile(vector<int> & arr , int n){
 
// Taking array Total Sum
int tSum = 0;
for(int i = 0; i < n; i++){
 	tSum = tSum + arr[i];
}

vector<vector<int>> dp(n + 1 , vector<int>(tSum + 1 , -1));

//ittrate over total sum and send each element to the subset to find the subset of each element
for(int i = 0; i <= tSum; i++){
	solve(arr , i , n - 1 , dp);
}

int s1 = 0;
int s2 = 0;

int mini = 1e9;


// now we can check in dp table if the i having subset then we need it
for(int i = 0; i < tSum; i++){

	if(dp[n - 1][i] == true){
       
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

 cout << "Test Cases: " << Utile(arr , n) << endl;


}