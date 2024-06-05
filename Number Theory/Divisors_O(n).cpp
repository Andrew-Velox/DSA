#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    ll n; cin >>n;
    ll cnt=0;
    
    for(int x=1; x<=n; x++){
        if(n%x==0) cnt++;
    }

    cout << cnt << endl;
    
    return 0;
}