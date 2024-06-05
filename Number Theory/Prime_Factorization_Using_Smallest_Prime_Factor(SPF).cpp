#include <bits/stdc++.h>
#define ll long long
using namespace std;


// ----------------- O(sqrt(n))---------------------
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n=48;

    map<ll,ll> cnt;
    for(int x=2; x*x<=n; x++){
        if(n % x == 0){
            while( n % x == 0){
                cnt[x]++;
                n/=x;
            }
        }
    }

    if(n>1) cnt[n]++;


    for(auto val= cnt.begin(); val!=cnt.end(); val++){
        cout << "(" <<  val->first << "^" << val->second << ")";

        auto tmp = val;
        if(++tmp !=cnt.end()) cout << " X ";
    }

    cout << endl;
    
    return 0;
}