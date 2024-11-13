#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>


const int N=1e5+10;
bool vis[N];
vector<pll> G[N];

class cmp{
    public:
        bool operator()(pll a,pll b){
            return a.second > b.second;
        }
};

ll prims(ll st){
    priority_queue<pll,vector<pll>,cmp> pq;
    ll min_cost=0;
    pq.push({st,0});

    while(!pq.empty()){
        pll par = pq.top();
        pq.pop();

        ll u = par.first;

        if(vis[u]) continue;

        min_cost+=par.second;
        vis[u]=true;

        for(auto [a,b]: G[u]){
            if(vis[a]==false){
                pq.push({a,b});
            }
        }

    }

    return min_cost;
}



int main(){
    
    ll n,e;
    cin >> n >> e;

    ll total_cost=0;
    
    while(e--){
        ll u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
        total_cost += w;
    }
    

    
    ll minimum_cost=prims(0);
    

    cout << "Total Cost: " << total_cost << endl;
    cout << "Minimum Cost: " << minimum_cost << endl;
    
    return 0;
}

/* 
input:
5 7
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9
output:
Total Cost: 40
Minimum Cost: 16
 */
