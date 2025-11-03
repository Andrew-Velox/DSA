#include <bits/stdc++.h>
#define ll long long
using namespace std;
#ifdef velox
#include "debug.h"
#else
#define debug(x...)
#endif

const ll N=2e5+10;
vector<ll> v(N);
pair<ll,ll> tree[4*N];


pair<ll,ll> marge(pair<ll,ll> &a, pair<ll,ll> &b){
    pair<ll,ll> ans;
    ans.first=min(a.first,b.first);
    ans.second=0;

    if(ans.first==a.first) ans.second+=a.second;
    if(ans.first==b.first) ans.second+=b.second;
    return ans;
}

void make(ll node,ll b, ll e){
    if(b==e){
        tree[node].first=v[e];
        tree[node].second=1;
        return;
    }

    ll mid=(b+e)/2;
    ll l=node*2;
    ll r=node*2+1;

    make(l,b,mid);
    make(r,mid+1,e);

    tree[node]=marge(tree[l],tree[r]);
    

}



void update(ll node, ll b, ll e, ll idx, ll val){
    if(idx>e || idx<b) return;
    if(b==e){
        tree[node].first=val;
        tree[node].second=1;
        return;
    }

    ll mid=(b+e)/2;
    ll l=node*2;
    ll r=node*2+1;

    update(l,b,mid,idx,val);
    update(r,mid+1,e,idx,val);

    tree[node]=marge(tree[l],tree[r]);
}


pair<ll,ll> query(ll node,ll b, ll e, ll i, ll j){

    if(i>e || j<b) return {INT_MAX, INT_MAX};
    if(i<=b && j>=e){
        return tree[node];
    }

    
    ll mid=(b+e)/2;
    ll l=node*2;
    ll r=node*2+1;

    pair<ll,ll> x= query(l,b,mid,i,j);
    pair<ll,ll> y= query(r,mid+1,e,i,j);
    return marge(x,y);

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    ll len,q;
    cin >> len >> q;

    for(int x=1; x<=len; x++) cin >> v[x];

    make(1,1,len);

    while(q--){
        ll op; cin >> op;
        if(op==1){
            ll idx,val;
            cin >> idx >> val;
            update(1,1,len,idx+1,val);
        }
        else{
            ll l,r;
            cin >> l >> r;
            pair<ll,ll> ans= query(1,1,len,l+1,r);
            cout << ans.first << " " << ans.second << endl;

            
        }
    }
    
    
    return 0;
}