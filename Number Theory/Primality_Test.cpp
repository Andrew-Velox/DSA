#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isPrime(ll n){
    for(int x=2; x*x<=n; x++){
        if(n%x==0)
            return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    ll n; cin >> n;

    if(isPrime(n)) cout << "Is Prime" << endl;
    else cout << "Not Prime" << endl;
    
    return 0;
}