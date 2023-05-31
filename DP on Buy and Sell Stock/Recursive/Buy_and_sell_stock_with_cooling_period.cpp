#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int index, int buyTrue , int n){

	//base case
	if(index >= n) return 0;

	//movement
	int buy = 0;
	int sell = 0;

	if(buyTrue == 1){
  
      buy = max(-arr[index] + solve(arr , index + 1 , 0 , n) , solve(arr , index + 1 , 1 , n));
	}
	else{
;
	  buy = max(arr[index] + solve(arr , index + 2 , 1 , n) , solve(arr , index + 1 , 0 , n));

	}

	return buy;

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<int> arr{1,2,3,0,2}; 
int n = arr.size();
 
cout << "Test Cases: " << solve(arr , 0 , 1 , n) << endl;


}