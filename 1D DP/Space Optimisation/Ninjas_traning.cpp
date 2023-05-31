#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>> arr , int days , int prevTast){

	vector<int> prev(4 , 0);

	//base case
    prev[0] = max(arr[0][1] , arr[0][2]);


    prev[1] = max(arr[0][0] , arr[0][2]);


    prev[2] = max(arr[0][0] , arr[0][1]);


    prev[3] = max(arr[0][0] , max(arr[0][1] , arr[0][2]));


	// MOvements
	// 0 has done with base case that why we start from 1
	for(int d = 1; d < prevTast; d++){ //For Every Days

		vector<int> temp(4 , 0);

		for(int l = 0; l < 4; l++){ // There is Different tasks

			int maxi = INT_MIN;

		    for(int t = 0; t <= 2; t++){

		    	if(t != l){

		    		int points = arr[d][t] + prev[t];
		    		maxi = max(maxi , points);
		    	}
		    }

		   temp[l] = maxi;
		}

		 prev = temp;
	}

    return prev[prevTast];
}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 
	freopen("outputf.in" , "w" , stdout);
   	#endif

  vector<vector<int>> arr {{10 , 40 , 70},
                          {20 , 50 , 80}, 
                          {30 , 60 , 90}};

   
   int n = arr.size();

 cout << "Test Case :" << solve(arr , n - 1 , n);



}