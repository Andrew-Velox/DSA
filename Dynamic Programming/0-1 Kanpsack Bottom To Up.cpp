#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n; cin >> n;
    int weight[n],values[n];

    for(int x=0; x<n; x++ ) cin >> weight[x];
    for(int x=0; x<n; x++) cin >> values[x];
    int W; cin >> W;

    int dp[n+1][W+1];

    for(int x=0; x<=n; x++){
        for(int y=0; y<=W; y++){
            if(x==0 || y==0) dp[x][y]=0;
        }
    }


    for(int x=1; x<=n; x++){
        for(int y=1; y<=W; y++){
            
            if(weight[x-1] <= y){ // second call =>  weight[1-1] = 2 , y = 2
                int opt1= dp[x-1][y-weight[x-1]] + values[x-1]; // dp[0][2-2] + 1 = 1
                int opt2= dp[x-1][y]; // dp[0][2] = 0

                dp[x][y] = max(opt1,opt2); // dp[1][2] = max(1,0) 
            }

            else{
                int opt2= dp[x-1][y];
                dp[x][y]=opt2;
            }
        }
    }


    for(int x=0; x<=n; x++){
        for(int y=0; y<=W; y++){
            cout << dp[x][y] << " ";
        }
        cout << endl;
    }


    // cout << dp[n][W] << endl;
    
    return 0;
}


/* 

input: 
4
2 3 4 5
1 3 5 3
8

output:
0 0 0 0 0 0 0 0 0 
0 0 1 1 1 1 1 1 1 
0 0 1 3 3 4 4 4 4 
0 0 1 3 5 5 6 8 8 
0 0 1 3 5 5 6 8 8  

*/
