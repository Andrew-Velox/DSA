#include <bits/stdc++.h>
using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#include "C:\Users\Mohabbat\Desktop\CP\debug.h"
#else
#define debug(x...)
#endif

void error_txt(){
    #ifndef ONLINE_JUDGE
    freopen("error.txt","w",stderr);
    #endif
}
void speed(){
    cin.tie(NULL);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}


vector<ll> binary(int x){
    vector<ll> bi;

    while(x>0){
        bi.push_back(x%2);
        x/=2;
    }
    reverse(bi.begin(), bi.end());
    return bi;
}



void solve(){
    

    // if n = 2^x then, n(binary) = 1xxxx(x==0) 
    // and n-1(binary) = 0xxxx(x==1);
    // then the and of this two will be -> 1000 & 0111 == 0000
    // so 0 means power of 2 ;-)

    // The first few powers of two are 1, 2, 4, 8, 16, 32, 64, 128 and so forth.
    // for(int x=0; x<=10; x++){
    //     if((x & (x-1)) == 0) cout << x << " YES" << endl;
    //     else cout << x << " NO" << endl;
    //     debug(binary(x), binary(x-1), (x & (x-1)));
    // }


    int n; cin >> n;
    // 0 is not power of two so we have two check this corner case ;-)
    if((n & (n-1)) == 0 && n!=0) cout << n << " YES" << endl;
    else cout << n << " NO" << endl;
    debug(binary(n), binary(n-1), (n & (n-1)));
    

}

int main(){
    error_txt();
    speed();
    ll t=1; //cin >> t;
    while(t--) solve();
    return 0;
}