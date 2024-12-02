#include <bits/stdc++.h>
#define ll long long
using namespace std;
#ifdef velox
#include "debug.h"
#else
#define dbg(x...)
#endif


void merge(vector<ll> &v, ll st, ll mid, ll end){
    ll lft_sz=mid-st+1;
    ll rht_sz=end-mid;
    vector<ll> lft_v,rht_v;
    

    for(int x=st; x<=mid; x++) lft_v.push_back(v[x]);
    
    for(int x=mid+1; x<=end; x++) rht_v.push_back(v[x]);


    ll cur=st;
    ll l=0,r=0;
    while(l<lft_sz && r<rht_sz){
        if(lft_v[l] <= rht_v[r]){
            v[cur]=lft_v[l];
            l++;
        }
        else{
            v[cur]=rht_v[r];
            r++;
        }
        cur++;
    }

    while(l<lft_sz) v[cur++]=lft_v[l++];
    while(r<rht_sz) v[cur++]=rht_v[r++];

}

void merge_sort(vector<ll> &v, ll st, ll end){

    if(st<end){
        ll mid=st+(end-st)/2;
        merge_sort(v,st,mid);
        merge_sort(v,mid+1,end);
        merge(v,st,mid,end);
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    vector<ll> v={1,3,5,53,32,34,3,2,338,29,423,2,6,7,64,4,10};
    ll sz=v.size();

    merge_sort(v,0,sz-1);

    for(auto val: v){
        cout << val << " ";
    }

    cout << endl;
    
    return 0;
}
