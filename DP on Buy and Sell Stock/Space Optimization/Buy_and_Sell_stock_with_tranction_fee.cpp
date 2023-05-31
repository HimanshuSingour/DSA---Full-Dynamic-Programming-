#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int index, int buyTrue , int n , int fee , vector<vector<int>>& dp){

   vector<int> next(buyTrue + 1 , 0);
   vector<int> curr(buyTrue + 1 , 0);

   for(int i = n - 1; i >= 0; i--){
   	 for(int j = 0; j <= 1; j++){

   	 	//movement
		int buy = 0;
		int sell = 0;

		if(j == 1){
	  
	      buy = max(-arr[i] + next[0] , next[1]);
		}
		else{
	       // transactions always happen when the sell done
		  sell = max(arr[i] - fee + next[1] , next[0]);

		}

		curr[j] = max(buy , sell);
   	 }

   	 next = curr;
   }

   return next[buyTrue];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<int> arr{6, 1, 7, 2, 8, 4 }; 
int n = arr.size();
int fee = 2;

vector<vector<int>> dp(n + 1 , vector<int>(fee + 1 , 0));
 
cout << "Test Cases: " << solve(arr , 0 , 1 , n , fee , dp) << endl;


}