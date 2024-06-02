#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:

    int u,v,c;

    Edge(int u,int v,int c){
        this->u=u;
        this->v=v;
        this->c=c;
    }

};

int v,e;


vector<Edge> EdgeList;
const int N=1e5+10;
int dis[N];

void bellMan(int st){
    for(int x=1; x<=v-1; x++){
        for(Edge val: EdgeList){
            int u,v,c;
            u=val.u;
            v=val.v;
            c=val.c;

            if(dis[u] < INT_MAX && dis[u]+c < dis[v]){
                dis[v]=dis[u]+c;
            }
        }
    }
}


int main(){
    cin >> v >>e;

    while(e--){
        int u,v,c;
        cin >> u >> v >> c;

        EdgeList.push_back(Edge(u,v,c));
        
        // EdgeList.push_back(Edge(v,u,c)); // for undirected graph add this line
    }

    for(int x=0; x<v; x++) dis[x]=INT_MAX;
    
    
    int st; cin >> st;
    dis[st]=0;

    bellMan(st);

    bool cycle=false;

    for(Edge val: EdgeList){
        int u,v,c;
        u=val.u;
        v=val.v;
        c=val.c;

        if(dis[u] < INT_MAX && dis[u]+c < dis[v]){
           cycle=true;
           break;     
        }
    }

    if(cycle) cout << "Cycle Detect. NO Answere" << endl;
    
    else{
        for(int x=0; x<v; x++){
            cout << x << " -> " << dis[x] << endl;
        }
    }

    
    return 0;
}

/* input: 
3 3
0 1 -1
1 2 2
2 0 -3
0

output:

Cycle Detect. NO Answere

 */