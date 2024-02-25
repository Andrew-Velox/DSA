#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dp[1005][1005];


int Count_subset_sum(int ar[], int len, int sum){

    if(len==0){
        if(sum==0) return 1;
        else return 0;
    }

    if(dp[len][sum]!=-1) return dp[len][sum];

    if(ar[len-1] <= sum){
        int opt1= Count_subset_sum(ar,len-1, sum-ar[len-1]);
        int opt2= Count_subset_sum(ar,len-1, sum);

        return dp[len][sum]=opt1+opt2;
    }
    else return dp[len][sum] =Count_subset_sum(ar,len-1,sum);
}

int main(){
    int n;
    cin >> n;

    int ar[n];
    for(int x=0; x<n; x++) cin >> ar[x];

    int sum;
    cin >> sum;

    // ------- initializing dp array with -1 ----------
    for(int x=0; x<=n; x++){
        for(int y=0; y<=sum; y++){
            dp[x][y]=-1;
        }
    }

    cout << Count_subset_sum(ar,n,sum) <<endl;
    
    return 0;
}
