#include <bits/stdc++.h>
#define ll long long
using namespace std;


map<ll,ll> cnt;
void prime_factorization(ll n){
    for(int x=2; x*x<=n; x++){
        if(n%x==0){
            while(n%x==0){
                cnt[x]++;
                n/=x;
            }
        }
    }

    if(n>1) cnt[n]++;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    ll n = 90;
    prime_factorization(n);


    //---------show prime Divisors-------------
    cout << "Prime Divisors: ";
    for(auto val= cnt.begin(); val!=cnt.end(); val++){
        cout << "(" <<  val->first << "^" << val->second << ")";

        auto tmp = val;
        if(++tmp !=cnt.end()) cout << "X";
    }
    cout << endl;

    // cnt total divisors---------------------------
    ll total_Divisors=1;
    for(auto val: cnt){
        total_Divisors*=val.second+1;
    }
    cout << "Total Divisors: " << total_Divisors << endl;


    // count total sum of Divisors---------------------
    ll total_Divisors_sum=1;
    for(auto val: cnt){
        ll power=1;
        ll get=1;
        for(int x=1; x<=val.second; x++){
            get+=(val.first*power);
            power=val.first*power; // alternative of pow(x,y) function
        }

        total_Divisors_sum*=get;
    }
    cout << "Total Divisors Sum: " << total_Divisors_sum << endl;

    
    return 0;
}