//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A

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
vector<ll> cnt(4*N);

void make(ll node,ll begin,ll end){
    if(end==begin){
        cnt[node]=v[begin];
        return;
    }

    ll mid = (begin+end)/2;
    ll left = node*2;
    ll right = (node*2)+1;

    make(left,begin,mid);
    make(right,mid+1,end);

    cnt[node] = cnt[left]+cnt[right];

}

void update(ll node, ll begin, ll end, ll indx, ll val){

    if(indx<begin || indx>end){
        return;
    }
    if(begin==end){
        cnt[node]=val;
        return;
    }

    ll mid = (begin+end)/2;
    ll left = node*2;
    ll right = (node*2)+1;

    update(left,begin,mid,indx,val);
    update(right,mid+1,end,indx,val);

    cnt[node] = cnt[left]+cnt[right];
}


ll query(ll node, ll begin, ll end, ll i, ll j){
    
    if(i>end || j<begin){
        return 0;
    }
    if(i<=begin && j>=end){
        return cnt[node];
    }
    
    
    ll mid = (begin+end)/2;
    ll left = node*2;
    ll right = (node*2)+1;

    return query(left,begin,mid,i,j) + query(right,mid+1,end,i,j);
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    ll len,q;
    cin >> len >> q;

    for(int x=1; x<=len; x++) cin >> v[x];

    make(1,1,len);
    while(q--){
        ll get; cin >> get;

        if(get==1){
            ll indx,val;
            cin >> indx >> val;
            indx++;
            update(1,1,len,indx,val);
        }
        else{
            ll i,j;
            cin >> i >> j;
            i++;
            ll ans=query(1,1,len,i,j);
            cout << ans << endl;
        }
    }


    
    return 0;
}

// input:
// 5 5
// 5 4 2 3 5
// 2 0 3
// 1 1 1
// 2 0 3
// 1 3 1
// 2 0 5


// output: 
// 11
// 8
// 14
