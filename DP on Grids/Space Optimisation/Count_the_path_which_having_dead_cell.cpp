#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>>& grid , int row , int col , vector<vector<int>>& dp){
    
    // base case 

    vector<int> prev(row + 1 , 0); // for previous row

    for(int i = 0; i < row; i++){

    	vector<int> curr(row + 1 , 0); // for current row

    	for(int j = 0; j < col; j++){

    		if(i >= 0 && j >= 0 && grid[i][j] == -1) curr[j] = 0;
    		else if(i == 0 && j == 0) curr[j] = 1;
    		 
    		else{

                int down = 0;
                int right = 0; 

                if(i > 0){
                	down = prev[j];
                }

                if(j > 0){
                	right = curr[j - 1];;
                }

	            curr[j] = down + right;
    		}
    	}

    	prev = curr;
    }

    return prev[col - 1];
}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif


   	vector<vector<int>> grid {{0 , 0 , 0 , 0}, 
   	                          {0 , -1 , 0 , 0},
   	                          {0 , 0 , 0  , 0}};

   int n = grid.size();
   int m = grid[0].size();

   vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , 0));

   	cout << "Test Cases: " << solve(grid , n , m  , dp) << endl;


}