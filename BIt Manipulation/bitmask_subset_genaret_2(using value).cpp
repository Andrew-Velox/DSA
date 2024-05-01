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
#define endl '\n'
#define fx(x) fixed<<setprecision(x)



void solve(){
    int n; cin >> n;

    vector<ll> v(n);

    for(int x=0; x<n; x++) cin >> v[x];


    for(int x=0;  x < (1 << n); x++){
        for(int y=0; y<n; y++){
            if((x >> y) & 1){
                cout << v[y] << " ";
            }
        }
        cout << endl;
    }
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t=1; //cin >> t;
    while(t--) solve();
    return 0;
}

/* 

input: 
3
4 6 5

output:
4 
6 
4 6 
5 
4 5 
6 5 
4 6 5

 */