#include <bits/stdc++.h>
using namespace std;


const int N= 1e5+10;
vector<int> ar[N];


bool visit[N];
bool path[N];

bool ans;

void dfs(int st){
    visit[st]=true;
    path[st]=true;

    for(int x: ar[st]){

        if(path[x]==true) ans=true;
        if(visit[x]==false){
            dfs(x);
        }
    }

    path[st]=false;

}

int main(){
    int v,e;
    cin >> v >> e;

    while(e--){
        int a,b;
        cin >> a >> b;

        ar[a].push_back(b);

    }
    
    memset(visit,false,sizeof(visit));
    memset(path,false,sizeof(path));


    for(int x=0; x<v; x++){
        if(visit[x]==false){
            dfs(x);
        }
    }
    if(ans) cout << "Cycle detected" << endl;
    else cout << "Not Cycle" << endl;
    
    return 0;
}

/* 

input:
7 8
5 6
4 5
0 4
0 6
1 0
1 2
2 3
6 4


output:
Cycle detected


*/
