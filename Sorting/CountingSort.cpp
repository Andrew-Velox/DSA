#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;


int main(){

    int len; cin>>len;
    int ar[len];
    int mx=0;
    for(int x=0; x<len; x++){
        cin >> ar[x];
        mx=max(mx, ar[x]) ;
    }
    int cnt[mx+1]={0};

    for(int x=0; x<len; x++) cnt[ar[x]]++;

    for(int x=1; x<=mx; x++){
        cnt[x]+=cnt[x-1];
    }

    int output[len];
    for(int x=len-1; x>=0; x--){
        cnt[ar[x]]--;
        output[cnt[ar[x]]]=ar[x];
    }

    for(int x=0; x<len; x++) ar[x]=output[x];

    for(int x=0; x<len; x++) cout << ar[x] << " ";
    cout << endl;

    
    return 0;
}
