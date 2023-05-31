#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>> &grid ,  int n ,int m, vector<vector<vector<int>>> &dp){
    

    vector<vector<int>> prev(m + 1 , vector<int>(m + 1 , 0));
    vector<vector<int>> curr(m + 1 , vector<int>(m + 1 , 0));



    for(int j1 = 0; j1 < m; j1++){

    	for(int j2 = 0; j2 < m; j2++){
             
            if(j1 == j2) prev[j1][j2] = grid[n - 1][j1];
            else prev[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    	}
    }

    for(int i = n - 2; i >= 0; i--){

    	for(int j1 = 0; j1 < m; j1++){

    		for(int j2 = 0; j2 < m; j2++){

		     // Moment
			    int maxi = INT_MIN;

			    // for 1 alice movement, bob have three movement , or vice versa
			    for(int d1 = -1; d1 <= +1; d1++){
			    	for(int d2 = -1; d2 <= +1; d2++){

			    		int ans = 0;

						if (j1 == j2) ans = grid[i][j1];
			            else ans = grid[i][j1] + grid[i][j2];

			            if ((j1 + d1 < 0 || j1 + d1 >= m) ||
			              (j2 + d2 < 0 || j2 + d2 >= m))

			              ans += -1e9;

			            else
			              ans += prev[j1 + d1][j2 + d2];

			           maxi = max(maxi , ans);
			    	}
			    }

			    curr[j1][j2] = maxi;
    		}
    	}

    	prev = curr;
    }

    return curr[0][m - 1];
   
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

   
   	vector<vector<int>> grid{ {3 , 7},
                              {7 , 6}};
                           
  int n = grid.size();
  int m = grid[0].size();

  vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>>(m + 1 , vector<int>(m , 0)));

 cout << "Test Cases: " << solve(grid , n ,  m , dp) << endl;


}