#include <bits/stdc++.h>
using namespace std;

#ifndef velox
#include "debug.h"
#else
#define debug(x...)
#endif

#define ll long long
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define unq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl "\n"
#define fx(x) fixed<<setprecision(x)

// ---------- Time Complexity ---------------- //
// -------------- O(n*2^n) ------------------- //

void solve(){
    int n; cin >> n; // (0 -> (2^n -1 ))
    
    for(int x=0; x < (1 << n); x++){ // (1 << n) => 8 
        cout << x << " -> ";
        for(int y=0; y<n; y++){ // (sps -> x=3 and y=0) (bi(3) -> 011 )
            if((x >> y) & 1){ // formula of kth bit is on or off (sps -> (3>>0)&1 => true(1))  
                cout << 1;
            }
            else cout << 0;
        }

        cout << endl;
    }
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}



/* 

input:
3 

output:
0 -> 000
1 -> 100
2 -> 010
3 -> 110
4 -> 001
5 -> 101
6 -> 011
7 -> 111

*/