#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>>& triangle , int row , int col , int n , vector<vector<int>>& dp){
  
// opposite of recursion is tabulation
    vector<int> front(n + 1 , 0);

	// for i(row) there is 4 j(col) So, we have 4 base case to n - 1 
	for(int j = 0; j < n; j++){
		front[j] = triangle[n -1 ][j];
	}

	for(int i = n - 2; i >= 0; i--){

		 vector<int> curr(n + 1 , 0);
		for(int j = i; j >= 0; j--){

			int bottom = triangle[i][j] + front[j];
			int diagonal = triangle[i][j] + front[j + 1];

			curr[j] = min(bottom , diagonal); 
		}

		front = curr;
	}

	return front[col];
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

   	vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , 0));

   	cout << "Test Cases: " << solve(triangle , 0, 0 , n , dp) << endl;


}