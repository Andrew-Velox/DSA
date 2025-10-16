#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#ifdef velox
#include "debug.h"
#else
#define dbg(x...)
#endif

#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define unq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define set_bits(x) __builtin_popcountll(x)
#define fst_zero(x) 63-__builtin_ctzll(x)
#define lst_zero(x) __builtin_ctzll(x)
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) ((x/gcd(x,y))*y)
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define ceil(x,y) ((x+y-1)/y)
#define ll long long
#define pb push_back
#define endl '\n'
#define fx(x) fixed<<setprecision(x)
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll MOD = 1e9+7;

void file(){
    #ifdef velox
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
}



void solve(){
    ll n; cin >> n;
    vector<ll> v(n);

    for(int x=0; x<n; x++) cin >> v[x];


    vector<ll> get;

    get.pb(v[0]);

    for(int x=1; x<n; x++){
        if(v[x]>get.back()) get.pb(v[x]);
        else{
            ll in = lower_bound(get.begin(), get.end(), v[x]) - get.begin();

            get[in]=v[x];
        }
    }

    cout << get.size() << endl;
    
}

int main(){
    // file();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
