#include <bits/stdc++.h>
using namespace std;
vector<int> v[10005];

bool place[10005];


void bfs(int src){
    queue<int> q;
    q.push(src);
    place[src]=true;

    while(!q.empty()){
        int src_ar_val=q.front();
        q.pop();

        cout << src_ar_val << " ";

        for(int val: v[src_ar_val]){
            if(place[val]==false){
                q.push(val);
                place[val]=true;
            }
        }
    }
    cout << endl;
}

int main(){
    int n,e;
    cin >> n >> e;

    while(e--){
        int a,b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    int src;
    cin >> src;

    memset(place,false,sizeof(place));
    bfs(src);

    return 0;
}

/* input:

6 6
0 1
1 2
2 5
2 4
1 3
3 4
0

output:

0 1 2 3 5 4 

 
*/
