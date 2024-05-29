#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;

// ----------------------- O((V+E)logV) ------------------------ //


vector<pair<int,int>> vi[N];
int dis[N];

class cmp{
    public:
        bool operator()(pair<int,int> a,pair<int,int> b){
            return a.second > b.second;
        }
};

void dijkstra(int st){
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    pq.push({st,0});
    dis[st]=0;

    while(!pq.empty()){
        pair<int,int> par=pq.top();
        pq.pop();

        int parent_node=par.first;
        int parent_cost=par.second;

        for(pair<int,int> child: vi[parent_node]){

            int child_node= child.first;
            int child_cost= child.second;

            if(parent_cost+child_cost < dis[child_node]){
                dis[child_node]=parent_cost + child_cost;
                pq.push({child_node,dis[child_node]});
            }

        }
    }
}

int main(){
    int v,e;
    cin >> v >> e;

    while(e--){
        int a,b,c;
        cin>>a >> b >>c;
        
        vi[a].push_back({b,c});
        vi[b].push_back({a,c});
    }

    int st; cin >> st;

    for(int x=0; x<N; x++) dis[x]=INT_MAX;

    dijkstra(st);
    
    for(int x=0; x<v; x++){
        cout << x << " -> " << dis[x] << endl;
    }
    return 0;
}