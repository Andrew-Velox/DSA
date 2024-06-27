#include <bits/stdc++.h>
using namespace std;
// -------------------- O(a(n)) ----------------- //
vector<int> par;
vector<int> sz;
vector<int> level;
void initial(int n){
    for(int x=0; x<=n; x++){
        par.push_back(-1);
        sz.push_back(1);
        level.push_back(0);
    }

}

int find(int node){
    if(par[node]==-1) return node;

    return par[node]=find(par[node]);
}

void unionn(int node1,int node2){ // not need this 
    int leaderA=find(node1);
    int leaderB=find(node2);
    par[leaderA]=leaderB;
}

void union_by_level(int node1, int node2){
    int leaderA=find(node1);
    int leaderB=find(node2);

    if(level[leaderA] > level[leaderB]){
        par[leaderB]=leaderA;
    }
    else if(level[leaderB] > level[leaderA]){
        par[leaderA]=leaderB;
    }
    else{
        par[leaderA]=leaderB;
        level[leaderB]++;
    }
}





int main(){
    initial(7);

    union_by_level(1,2);
    union_by_level(2,3);
    union_by_level(4,5);
    union_by_level(5,6);
    union_by_level(1,4);

    cout << find(1) << endl;
    cout << find(4) << endl;
    
    return 0;
}