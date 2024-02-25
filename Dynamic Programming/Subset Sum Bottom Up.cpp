#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;

    int ar[n];

    for(int x=0; x<n; x++) cin>> ar[x];

    int sum;
    cin >> sum;


    bool dp[n+1][sum+1];

    dp[0][0]=true;
    for(int x=1; x<=sum; x++){
        dp[0][x]=false;
    }

    for(int x=1; x<=n; x++){
        for(int y=0; y<=sum; y++){

            if(ar[x-1] <= y){
                bool opt1= dp[x-1][y-ar[x-1]];
                bool opt2= dp[x-1][y];

                dp[x][y] = opt1 || opt2;
            }
            else{
                dp[x][y]=dp[x-1][y];
            }
        }
    }

    // cout << dp[1][sum] <<endl;

    for(int x=0; x<=n; x++){
        for(int y=0; y<=sum; y++){
            if(dp[x][y]==true) cout << "T ";
            else cout << "F ";
        }
        cout <<endl;
    }
    
    return 0;
}


// input:

// 4
// 1 2 3 6
// 7

// output:

// T F F F F F F F 
// T T F F F F F F 
// T T T T F F F F 
// T T T T T T T F 
// T T T T T T T T 
