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

    // int dis[100004];
    // vector<Edge> EdgeList;

    while(e--){
        int u,v,c;
        cin >> u >> v >> c;

        EdgeList.push_back(Edge(u,v,c));

    }

    for(int x=0; x<v; x++){
        dis[x]=INT_MAX;
    }

    int st; cin >> st;
    dis[st]=0;

    bellMan(st);


    // for(int x=1; x<=v-1; x++){
    //     for(Edge y: EdgeList){
    //         int u,v,c;

    //         u=y.u;
    //         v=y.v;
    //         c=y.c;

    //         if(dis[u] < INT_MAX && dis[u]+c < dis[v]){
    //             dis[v]=dis[u]+c;
    //         }
    //     }
    // }

    for(int x=0; x<v; x++){
        cout << x << " -> " << dis[x] << endl;
    }


    // for(Edge x: EdgeList){
    //     cout << x.u << " " << x.v << " " << x.c << endl;
    // }

    
    return 0;
}

/* input: 
4 4
0 2 5
0 3 12
2 1 2
1 3 3
0

output:

0 -> 0
1 -> 7
2 -> 5
3 -> 10
 */