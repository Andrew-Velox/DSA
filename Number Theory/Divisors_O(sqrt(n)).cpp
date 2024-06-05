#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    ll n; cin >> n;

    vector<ll> divisors;

    for(int x=1; x*x<=n; x++){
        if(n%x==0){
            divisors.push_back(x);
            if(x*x!=n) divisors.push_back(n/x);
        }
    }

    sort(divisors.begin(), divisors.end());

    for(auto val: divisors) cout << val << " ";
    cout << endl;
    
    return 0;
}