#include<bits/stdc++.h>
using namespace std;

int solve(v+ector<int> &arr , int n){

 vector<int> ans;
 ans.push_back(arr[0]);

 for(int i = 1; i < n; i++){
 	if(arr[i] > ans.back()){
 		ans.push_back(arr[i]);
 	}
 	else{

 		int index = lower_bound(ans.begin() , ans.end() , arr[i]) - ans.begin();
 		ans[index] = arr[i];
 	}
 }

 return ans.size();

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<int> arr{10,9,2,5,3,7,101,18}; 
int n = arr.size();


cout << "Test Cases: " << solve(arr , n) << endl;


}