#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int index, int buyTrue , int n , int k){

	//base case
	if(index == n || k == 0) return 0;

	//movement
	int buy = 0;
	int sell = 0;

	if(buyTrue == 1){
  
      buy = max(-arr[index] + solve(arr , index + 1 , 0 , n , k) , solve(arr , index + 1 , 1 , n , k));
	}
	else{
;
	  buy = max(arr[index] + solve(arr , index + 1 , 1 , n , k - 1) , solve(arr , index + 1 , 0 , n , k));

	}

	return buy;

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<int> arr{12, 14, 17, 10, 14, 13, 12, 15}; 
int n = arr.size();
int k = 3;
 
cout << "Test Cases: " << solve(arr , 0 , 1 , n , k) << endl;


}