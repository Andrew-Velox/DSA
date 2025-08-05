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




set<ll> gg;
void tow_num_patt(string s, ll len, char a, char b, ll cnt_a,ll cnt_b){
    if (s.length()>len) return;

    
    if(s.size()) gg.insert(stoll(s));
    // if(s.size() && cnt_a==cnt_b) get.insert(stoll(s)); //for same number of a&b
    

    tow_num_patt(s + a, len, a, b,cnt_a+1,cnt_b);
    tow_num_patt(s + b, len, a, b,cnt_a,cnt_b+1);
}



void solve(){
    dbg(gg);

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1;
    cin >> t;
    tow_num_patt("",6,'1','0',0,0);
    while(t--) solve();
    return 0;
}
