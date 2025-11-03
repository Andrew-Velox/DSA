#include <bits/stdc++.h>
#define ll long long
using namespace std;
#ifdef velox
#include "debug.h"
#else
#define debug(x...)
#endif


const ll N = 1e5+10;
vector<ll> v(N);
vector<ll> dp(4*N);

void make(ll node,ll beg,ll end){
    if(end==beg){
        dp[node]=v[end];
        return;
    }

    ll mid=(beg+end)/2;
    ll left=node*2;
    ll right=(node*2)+1;

    make(left,beg,mid);
    make(right,mid+1,end);

    dp[node] = min(dp[left],dp[right]);
}

void update(ll node, ll beg,ll end, ll in, ll val){

    if(in<beg || in>end) return;
    if(beg==end){
        dp[node]=val;
        return;
    }

    ll mid=(beg+end)/2;
    ll left=node*2;
    ll right=(node*2)+1;

    update(left,beg,mid,in,val);
    update(right,mid+1,end,in,val);

    dp[node]=min(dp[left],dp[right]);
    
}
ll query(ll node, ll beg,ll end, ll i, ll j){

    if(i>end || j<beg) return INT_MAX;
    
    if(i<=beg && j>=end){
        return dp[node];
    }

    ll mid=(beg+end)/2;
    ll left=node*2;
    ll right=(node*2)+1;

    
    return min(query(left,beg,mid,i,j),query(right,mid+1,end,i,j));
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    ll len,k;
    cin >> len >> k;
    for(int x=1; x<=len; x++) cin >> v[x];


    make(1,1,len);

    while(k--){
        ll q; cin >> q;
        if(q==1){
            ll in,val;
            cin >> in >> val;
            update(1,1,len,in+1,val);
        }
        else{
            ll l,r;
            cin >> l >> r;

            cout << query(1,1,len,l+1,r) << endl;
        }
    }
    
    return 0;
}