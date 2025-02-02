#include <bits/stdc++.h>
using namespace std;
// -------------------- O(a(n)) ----------------- //
vector<int> par;
vector<int> sz;
void initial(int n){
    for(int x=0; x<=n; x++){
        par.push_back(-1);
        sz.push_back(1);
    }

}

int find(int node){
    if(par[node]==-1) return node;

    return par[node]=find(par[node]);
}

void union_by_size(int node1,int node2){
    int leaderA=find(node1);
    int leaderB=find(node2);
    if(leaderA==leaderB) return;
    if(sz[leaderA] > sz[leaderB]){
        par[leaderB]=leaderA;
        sz[leaderA]+=sz[leaderB];
    }
    else{
        par[leaderA]=leaderB;
        sz[leaderB]+=sz[leaderA];
    }
    
}


int main(){
    initial(7);

    union_by_size(1,2);
    union_by_size(2,3);
    union_by_size(4,5);
    union_by_size(5,6);
    union_by_size(1,4);

    cout << find(1) << endl;
    cout << find(4) << endl;
    
    return 0;
}
