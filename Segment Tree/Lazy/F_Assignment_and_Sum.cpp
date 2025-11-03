#include <bits/stdc++.h>
#define ll long long
using namespace std;
#ifdef velox
#include "debug.h"
#else
#define dbg(x...)
#endif


const ll N = 1e5+10;
vector<ll> v(N),t(4*N),lazy(4*N);

void marge(ll n, ll b, ll e){
    if(lazy[n]==-1) return;

    t[n]=(e-b+1)*lazy[n];
    if(b!=e){
        ll l=n*2;
        ll r=(n*2)+1;
        lazy[l]=lazy[n];
        lazy[r]=lazy[n];
    }
    lazy[n]=-1;
}


void make(ll n,ll b, ll e){
    lazy[n]=-1;
    if(b==e){
        t[n]=v[0];
        return;
    }

    ll mid=(b+e)/2;
    ll l=(n*2);
    ll r=(n*2)+1;

    make(l,b,mid);
    make(r,mid+1,e);
    t[n]= t[l]+t[r];
}


void update(ll n,ll b,ll e, ll i,ll j, ll val){
    marge(n,b,e); // lazy
    if(i>e || j<b) return;

    if(i<=b && j>=e){
        lazy[n] = val;
        marge(n,b,e); // lazy
        return;
    }

    ll mid=(b+e)/2;
    ll l=(n*2);
    ll r=(n*2)+1;

    update(l,b,mid,i,j,val);
    update(r,mid+1,e,i,j,val);
    t[n]= t[l]+t[r];

}


ll query(ll n, ll b, ll e, ll i, ll j){
    marge(n,b,e); // lazy
    if(i>e || j<b) return 0;

    if(i<=b && j>=e) return t[n];

    ll mid=(b+e)/2;
    ll l=(n*2);
    ll r=(n*2)+1;

    return query(l,b,mid,i,j)+query(r,mid+1,e,i,j);
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);


    ll len,q; cin >> len >> q;
    make(1,1,len);

    while(q--){
        ll op; cin >> op;
        if(op==1){
            ll l,r,val; cin >> l >> r >> val;
            l++;
            update(1,1,len,l,r,val);
        }
        else{
            ll i,j; cin >> i >> j;
            i++;
            cout << query(1,1,len,i,j) << endl;
        }
    }
    
    
    return 0;
}