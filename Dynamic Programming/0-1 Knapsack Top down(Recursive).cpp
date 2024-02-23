#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN=1000;
const int maxW=1000;
int dp[maxN][maxW];

// ----------------------Time Complexity----------------
// ------------------------ O(N*W)----------------------
int knapsack(int n, int weight[], int values[], int w){

    if(n<0 || w==0) return 0;
    if(dp[n][w] != -1){
        return dp[n][w];
    }
    if(weight[n] <= w){ 
        // check by taking its value (1)
        int opt1 = knapsack(n-1,weight,values, w-weight[n])+values[n];

        // check without taking its value (0)
        int opt2 = knapsack(n-1,weight,values, w);
        dp[n][w] = max(opt1,opt2);
        return dp[n][w]; 
    }

    else{ // By not Taking its value (0) 
        int opt2= knapsack(n-1, weight, values, w);
        dp[n][w] = opt2;
        return dp[n][w]; 
      
    }

}

int main(){
    int n;
    cin >> n;

    int weight[n],values[n];
    for(int x=0; x<n; x++) cin >> weight[x];
    for(int x=0; x<n; x++) cin >> values[x];
    
    int w; cin >> w;

    for(int x=0; x<=n; x++){
        for(int y=0; y<=w; y++){
            dp[x][y]=-1;
        }
    }
    
    cout << knapsack(n-1,weight,values,w) << endl;
    return 0;
}

/* 

input: 
4
2 3 4 5
1 3 5 3
8

output:
8

*/
