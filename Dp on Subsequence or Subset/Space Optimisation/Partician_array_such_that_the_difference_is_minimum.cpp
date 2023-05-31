#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int index){



	 // Taking array Total Sum
	int tSum = 0;
	for(int i = 0; i < index; i++){
	 	tSum = tSum + arr[i];
	}

	vector<int> prev(tSum + 1 , 0);
	vector<int> curr(tSum + 1 , 0);


	vector<vector<int>> dp(index + 1 , vector<int>(tSum + 1 , 0));

   // base cases

	prev[arr[0]] = true;

	for(int i = 0; i < index; i++){
		  curr[0] = true;
	}

	
	for(int ind = 1; ind < index; ind++){

		

		for(int t = 1; t < tSum; t++){

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

// calculation for minimum difference
int s1 = 0;
int s2 = 0;

int mini = 1e9;


// now we can check in dp table if the i having subset then we need it
for(int i = 0; i < tSum; i++){

	if(prev[i] == true){
       
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