#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n; cin >> n;

    int ar[n];
    for(int x=0; x<n; x++) cin>> ar[x];

    int sum; cin >> sum;

    int dp[n+1][sum+1];
    dp[0][0]=1;

    for(int x=1; x<=sum; x++){
        dp[0][x]=0;
    }

    for(int x=1; x<=n; x++){
        for(int y=0; y<=sum; y++){

            if(ar[x-1] <= y){
                int opt1= dp[x-1][y-ar[x-1]];
                int opt2= dp[x-1][y];

                dp[x][y] = opt1 + opt2;
            }
              
            else dp[x][y]=dp[x-1][y];
        }
    }


    for(int x=0; x<=n; x++){
        for(int y=0; y<=sum; y++){
            cout << dp[x][y] << " ";
        }
        cout <<endl;
    }
    
    return 0;
}


// input:

// 6
// 1 2 3 4 5 6
// 7

// output:

// 1 0 0 0 0 0 0 0 
// 1 1 0 0 0 0 0 0 
// 1 1 1 1 0 0 0 0 
// 1 1 1 2 1 1 1 0 
// 1 1 1 2 2 2 2 2 
// 1 1 1 2 2 3 3 3 
// 1 1 1 2 2 3 4 4 

