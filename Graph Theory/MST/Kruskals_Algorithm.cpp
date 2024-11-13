#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int par[N];
int sz[N];

class Edge{
    public:

    int u,v,w;

    Edge(int u,int v,int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

void dsu_init(int n){
    for(int x=0; x<n; x++){
        par[x]=-1;
        sz[x]=1;
    }
}

int dsu_find(int node){
    if(par[node]==-1) return node;
    return par[node]=dsu_find(par[node]);
}

void dsu_union_by_size(int node1, int node2){
    int leaderA=dsu_find(node1);
    int leaderB=dsu_find(node2);

    if(sz[leaderA] < sz[leaderB]){
        par[leaderA]=leaderB;
        sz[leaderB]+=sz[leaderA];
    }
    else{
        par[leaderB]=leaderA;
        sz[leaderA]+=sz[leaderB];
    }


}

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}


int main(){
    
    int n,e;
    cin >> n >> e;

    dsu_init(n);

    vector<Edge> EdgeList;
    int total_cost=0;
    while(e--){
        int u,v,w;
        cin >> u >> v >>w;

        EdgeList.push_back(Edge(u,v,w));
        total_cost+=w;
    }


    sort(EdgeList.begin(), EdgeList.end(),cmp);
    // for(Edge val: EdgeList){
    //     cout << val.u << " " << val.v << " " << val.w << endl;
    // }

    int minimum_cost=0;
    for(Edge val: EdgeList){
        int leaderA=dsu_find(val.u);
        int leaderB=dsu_find(val.v);

        if(leaderA==leaderB) continue;
        else{
            dsu_union_by_size(val.u , val.v);
            minimum_cost+=val.w;
        }
    }


    cout << "Total Cost: " << total_cost << endl;
    cout << "Minimum Cost: " << minimum_cost << endl;
    
    return 0;
}
/* 
input: 
4 5
0 1 10 
1 3 15
2 3 4
2 0 6 
0 3 5

output:
Total Cost: 40
Minimum Cost: 19
 */
