#include <bits/stdc++.h>
#define ll long long
using namespace std;

// -------------------O(N*log(log(N)))-------------//
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    ll n; cin >> n;
    vector<bool> prime(n+1,true);

    for(int x=2; x*x<=n; x++){
        if(prime[x]){
            for(int y=x*x; y<=n; y+=x){
                prime[y]=false;
            }
        }
    }


    for(int x=2; x<=n; x++){
        if(prime[x]) cout << x << " ";
    }
    cout << endl;
    
    return 0;
}