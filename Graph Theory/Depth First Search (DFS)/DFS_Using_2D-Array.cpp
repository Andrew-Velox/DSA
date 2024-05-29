#include <bits/stdc++.h>
using namespace std;
const int N=100;
int vi[N][N];
bool visit[N];

void dfs(int str, int v){

    cout << str << " ";

    visit[str]=true;
    for(int x=1; x<=v; x++){
        if(vi[str][x] && visit[x]== false){
            dfs(x,v);
        }
    }
}

int main(){
    int v,e;
    cin >> v >> e;

    while(e--){
        int a,b;
        cin >> a >> b;

        vi[a][b]=1;
        vi[b][a]=1;
    }

    for(int x=0; x<=v; x++) visit[x]=false;

    int str; cin >> str;

    cout << "DFS Traversal: " ;
    dfs(str,v);
    cout << endl;


    return 0;
}
