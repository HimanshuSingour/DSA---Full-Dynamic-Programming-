#include<bits/stdc++.h>
using namespace std;

bool isPossible(string s1 , string s2){
 
 if(s1.size() != s2.size() + 1) return false;

 int i = 0;
 int j = 0;

 while(s1.size() > i){

 	if(s1[i] == s2[j]){
 		i++;
 		j++;
 	}
 	else{

 		i++;
 	}
 }

 if(i == s1.size() && j == s2.size()) return true;
 else false;

}

//comparator -> sort accounting to the string length
bool comp(string s1 , string s2){
	return s1.size() < s2.size();
}

int solve(vector<string> &arr , int n){
    
    //comparator -> sort accounting to the string length
	sort(arr.begin() , arr.end() , comp);

	vector<int> dp(n , 1);
	int maxi = INT_MIN;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){

			if(isPossible(arr[i] , arr[j]) && 1 + dp[j] > dp[i]){

				dp[i] = 1 + dp[j];
				maxi = max(maxi , dp[i]);
			}
		}
	}

	return maxi;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

vector<string> arr{"xbc","pcxbcf","xb","cxbc","pcxbc"}; 
int n = arr.size();

cout << "Test Cases: " << solve(arr , n) << endl;

}