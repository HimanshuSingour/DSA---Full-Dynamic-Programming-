#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> value , vector<int> weight , int W , int index){

	// base conditions
    if(index == 0){

    	if(weight[0] <= W){
    		return value[0];
    	}

    	return 0;
    }


	// movements
	int notPick = 0 + solve(value , weight , W , index - 1);

    int pick = INT_MIN;
	if(weight[index] <= W){

		pick = value[index] + solve(value , weight , W - weight[index] , index - 1);
	}


	return max(notPick , pick);

}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
  vector<int> value{1 , 2 , 3};
  vector<int> weight{4 , 5 , 1};
  int n = value.size();
  int W = 5;                     

 cout << "Test Cases: " << solve(value , weight , W , n - 1) << endl;


}