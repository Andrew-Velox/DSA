#include <bits/stdc++.h>
#define ll long long
using namespace std;

//------------1005*1005 size 2D array with (-1) values ---------
vector<vector<int>> dp(1005, vector<int>(1005,-1));

// -----------Time Complexity----------------
// ---------------O(N*M)---------------------
bool Subset_sum(int ar[], int len, int sum){

    if(len==0){
        if(sum==0) return true;
        else return false;
    }

    if(ar[len-1] <= sum){
        bool opt1= Subset_sum(ar,len-1,sum-ar[len-1]);
        bool opt2= Subset_sum(ar,len-1,sum);
        return opt1 || opt2;
    }

    else return Subset_sum(ar,len-1,sum);

}

int main(){
    
    int n;
    cin >> n;
    int ar[n];

    for(int x=0; x<n; x++) cin >> ar[x];

    
    int sum;
    cin >> sum;

    if(Subset_sum(ar,n,sum)){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    
    return 0;
}

/* 
Input: 
5
1 2 3 4 6
16

Output:
YES 

Input: 
5
1 2 3 4 6
17

Output:
NO 

*/
