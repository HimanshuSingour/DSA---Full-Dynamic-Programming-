#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> & arr , int index){

	// base case
	if(index == 0) return arr[index];
	if(index < 0) return 0;
 
   // Movement
    int notPick = 0 + solve(arr , index - 1);
    int Pick = arr[index] + solve(arr , index - 2);

    return max(Pick , notPick);
}

int helper(int arr[] , int n){

	vector<int> temp1;
    vector<int> temp2;
 
    for(int i = 0; i < n; i++){
    	if(i != 0) temp1.push_back(arr[i]);
    }

    for(int i = 0; i < n; i++){
    	if(i != n - 1) temp2.push_back(arr[i]);
    }
    
    int ans1 = solve(temp1 , temp1.size() - 1);
    int ans2 = solve(temp2 , temp2.size() - 1);

    return max(ans1 , ans2);

}



int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

    int arr[] = {2,7,9,3,1};
    int n = sizeof(arr) / sizeof(int);
 


   	cout << "Test Case :" << helper(arr , n);



}