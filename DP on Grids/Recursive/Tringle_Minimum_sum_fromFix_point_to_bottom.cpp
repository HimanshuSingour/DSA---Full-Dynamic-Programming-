#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>>& triangle , int row , int col , int n){
  
  // base case
	if(row == n - 1) return triangle[row][col];
	
	int bottom = triangle[row][col] + solve(triangle , row + 1, col , n);
	int diagonal = triangle[row][col] + solve(triangle , row + 1 , col + 1 , n);

	return min(bottom , diagonal);  

}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
   	vector<vector<int>> triangle {{1},
                                {2,3},
                                {3,6,7},
                                {8,9,6,10}};
                            

   	int n = triangle.size();
   	int m = triangle[0].size();

   	// vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));

   	cout << "Test Cases: " << solve(triangle , 0, 0 , n) << endl;


}