#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dp[1005][1005];

int subset_sum(int ar[],int len, int sum){
    if(len==0){
        if(sum==0) return 1;
        else return 0;
    }
    
    if(dp[len][sum]!= -1) return dp[len][sum];
    if(ar[len-1] <= sum) {
        int opt1=subset_sum(ar,len-1, sum - ar[len-1]);
        int opt2=subset_sum(ar,len-1, sum);

        return dp[len][sum]=opt1 + opt2;
    }
    else return dp[len][sum] = subset_sum(ar,len-1, sum);
}

int main(){
    int len;
    cin >> len;
    int ar[len];
    int sum=0;
    for(int x=0; x<len; x++){
        cin >> ar[x];
        sum+=ar[x];
    }

    if(sum%2!=0) cout << "NO" << endl;
    else{

        for(int x=0; x<=len; x++){
            for(int y=0; y<=sum/2; y++){
                dp[x][y]=-1;
            }
        }

        int ans = subset_sum(ar,len,sum/2);


        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}
