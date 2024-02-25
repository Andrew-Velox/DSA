#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    
    int n;
    cin >> n;
    int ar[n];
    int sum=0;

    for(int x=0; x<n; x++){
        cin >> ar[x];
        sum+=ar[x];
    }

    bool dp[n+1][sum+1];
    dp[0][0]=true;

    for(int x=1; x<=sum; x++) dp[0][x]=false;

    for(int x=1; x<=n; x++){
        for(int y=0; y<=sum; y++){
            if(ar[x-1] <= y){
                dp[x][y] = dp[x-1][y-ar[x-1]] ||dp[x-1][y];
            }

            else dp[x][y] = dp[x-1][y];
        }
    }

    vector<int> v;

    for(int x=0; x<=n; x++){
        for(int y=0; y<=sum; y++){

            if(dp[x][y]) v.push_back(y);
            // if(dp[x][y]) cout << y << " ";
            // else cout << 0 << " ";

        }
    }

    int ans=INT_MAX;

    for(int val: v){

        int s1=val;
        int s2=sum-s1;
        ans=min(ans,abs(s1-s2));
    }
    
    cout << ans << endl;
    
    return 0;
}

/* 
input:
4
1 5 4 11

output:
4 
*/
