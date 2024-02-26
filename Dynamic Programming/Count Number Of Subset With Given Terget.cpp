#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n; cin >> n;

    int dif;
    cin >> dif;
    int ar[n],sum=0;

    for(int x=0; x<n; x++){
        cin >> ar[x];
        sum+=ar[x];
    }

    int s1=dif+sum;

    if(s1%2!=0) cout << "Not Possible" << endl;
    else{

        s1/=2;
        int dp[n+1][s1+1];

        dp[0][0]=1;

        for(int x=1; x<=s1; x++) dp[0][x]=0;

        for(int x=1; x<=n; x++){
            for(int y=0; y<=s1; y++){
                if(ar[x-1] <= y){
                    dp[x][y] = dp[x-1][y-ar[x-1]] + dp[x-1][y];
                }
                else dp[x][y] = dp[x-1][y];
            }
        }


        // for(int x=0; x<=n; x++){
        //     for(int y=0; y<=s1; y++){
        //         if(dp[x][y]) cout << dp[x][y] << " ";
        //         else cout << dp[x][y] << " ";
        //     }
        //     cout << endl;
        // }

        
        cout << dp[n][s1] << endl;
    }
    
    return 0;
}

/* 

input: 
5 3
1 1 1 1 1

output:
5


 */
