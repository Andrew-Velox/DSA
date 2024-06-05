#include <bits/stdc++.h>
#define ll long long
using namespace std;

// ---------------O(N*log(log(N)))--------------------
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n=18;

    vector<bool> primes(n+1,true);

    for(int x=2; x*x<=n; x++){
        if(primes[x]){
            for(int y=x*x; y<=n; y+=x){
                primes[y]=false;
            }
        }
    }

    vector<ll> all_primes;
    for(int x=2; x<=n; x++) if(primes[x]) all_primes.push_back(x);
    

    // primes----------------------------
    for(auto val: all_primes) cout << val << " ";
    cout << endl << endl;


    map<ll,ll> cnt;

    ll index=0;
    while(n>1){
        if(n % all_primes[index]==0){
            cnt[all_primes[index]]++;
            n/= all_primes[index];
        }
        else index++;
    }


    // for printing-------------------------
    auto it=cnt.begin();
    for(auto val: cnt){
        it++;
        cout << "(" <<  val.first << "^" << val.second << ")";

        if(it!=cnt.end()) cout << " X ";

    }

    cout << endl;

    return 0;
}