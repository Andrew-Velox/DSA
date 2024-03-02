#include <bits/stdc++.h>
using namespace std;
const int N= 1e5+10;

vector<int> ar[N];

int parentArray[N];
bool visit[N];


bool check=false;

void bfs(int st){
    queue<int> q;

    q.push(st);
    visit[st]=true;

    while(!q.empty()){
        int par=q.front();
        q.pop();

        // cout << par << endl;

        for(int x: ar[par]){

            if(visit[x]==true && parentArray[par]!=x){
                check=true;
            }
            if(visit[x]==false){
                q.push(x);
                visit[x]=true;

                parentArray[x] = par;

            }
        }
    } 
}


int main(){
    int v,e;
    cin >> v >> e;

    while(e--){
        int a,b;
        cin >> a >> b;

        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    memset(visit,false,sizeof(visit));
    memset(parentArray,-1,sizeof(parentArray));

    for(int x=0; x<v; x++){
        if(visit[x]==false){
            bfs(x);
        }
    }

    // check parent of every nodes [-1 means that node has parent]
    for(int x=0; x<v; x++){
        cout << x << " ar parent-> " << parentArray[x] << endl;
    }

    cout << endl;

    if(check) cout << "Cycle Detected" << endl;
    else cout << "Not Detected" << endl;
    return 0;
}

/* 
input:

7 7
5 6
4 5
0 4
0 6
1 0
1 2
2 3


output:

0 ar parent-> -1
1 ar parent-> 0
2 ar parent-> 1
3 ar parent-> 2
4 ar parent-> 0
5 ar parent-> 4
6 ar parent-> 0

Cycle Detected

*/
