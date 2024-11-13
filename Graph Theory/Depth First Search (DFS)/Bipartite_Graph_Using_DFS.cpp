#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl '\n'


bool dfs(ll st,ll color, vector<ll>&colors, vector<ll> adj[]){
    colors[st]=color;

    for(auto val: adj[st]){

        if(colors[val]==-1){
            if(!dfs(val,1-color,colors,adj)) return false;
        }
        else if(colors[val]==color) return false;
    }
    return true;
}

bool isBipartite(ll len,vector<ll> adj[]){
    vector<ll> colors(len+1,-1);

    for(int x=1; x<=len; x++){
        if(colors[x]==-1){
            if(!dfs(x,0,colors,adj)) return false;
        }
    }

    return true;
}



int main(){
    ll n,k; cin >> n >> k;
    vector<ll> adj[n+1];

    while(k--){
        ll a,b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    bool bipartite = isBipartite(n,adj);

    if(bipartite) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

/*
input: 
6 5
1 4
1 5
2 5
2 6
3 6
output: YES 
*/
