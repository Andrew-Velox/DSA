#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define unq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl "\n"
#define fx(x) fixed<<setprecision(x)

#ifndef ONLINE_JUDGE
#include "C:\Users\Mohabbat\Desktop\CP\debug.h"
#else
#define debug(x...)
#endif


void speed(){
    cin.tie(NULL);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

vector<ll> binary(ll n){
    vector<ll> bi;

    while(n>0){
        bi.push_back(n%2);
        n/=2;
    }

    rev(bi);
    return bi;
}


void solve(){
    // ll n; cin >> n;

    // Even numbers have 0 as their least significant bit in binary form.
    // Odd numbers have 1 as their least significant bit in binary form.


    for(int x=1; x<=10; x++){
        vector<ll> ans = binary(x);

        cout << "Num:" <<  x << " Binary:";
        for(auto val: ans) cout << val;
        cout << " ";

        if(x & 1) cout << "=>odd" << endl;
        else cout << "=>even" << endl;
        cout << endl;
        debug(x, ans);
        // debug(x & 1);
    }


}

int main(){
    // error_txt();
    speed();
    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}