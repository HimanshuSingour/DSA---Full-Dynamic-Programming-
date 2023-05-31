#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int index, int buyTrue , int n , int fee){

	//base case
	if(index == n) return 0;

	//movement
	int buy = 0;
	int sell = 0;

	if(buyTrue == 1){
  
      buy = max(-arr[index] + solve(arr , index + 1 , 0 , n , fee) , solve(arr , index + 1 , 1 , n , fee));
	}
	else{
       // transactions always happen when the buy, sell both done...
	  sell = max(arr[index] - fee + solve(arr , index + 1 , 1 , n , fee) , solve(arr , index + 1 , 0 , n , fee));

	}

	return max(buy , sell);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<int> arr{1,3,2,8,4,9}; 
int n = arr.size();
int fee = 2;
 
cout << "Test Cases: " << solve(arr , 0 , 1 , n , fee) << endl;


}