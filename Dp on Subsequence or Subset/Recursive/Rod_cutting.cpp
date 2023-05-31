#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices , int N , int index){

	// base case
	if(index == 0){
		return N * prices[0];
	}

	// Movement
	int notPick = 0 + solve(prices , N , index - 1);

	int pick = INT_MIN;
    
    //i + 1 = roadleangth
    int rodLength = index + 1;
	if(rodLength <= N){
                                         // roadlength off
		pick = prices[index] + solve(prices , N - rodLength , index);
	}

	return max(pick , notPick);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif


   
  vector<int> prices{3, 5, 8, 9, 10, 17, 17, 20}; 
  int N = 8;

  int n = prices.size();

 cout << "Test Cases: " << solve(prices, N , n - 1) << endl;


}