#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
vector<int> vi[N];
bool check[N];
// ----------shortest path ---------- //

int level[N];
int par[N];

void bfs(int st){
    queue<int> q;
    q.push(st);

    check[st]=true;
    level[st]=0;
    
    while(!q.empty()){
        int surur_val=q.front();
        q.pop();


        for(int val: vi[surur_val]){
            if(!check[val]){
                q.push(val);
                level[val]=level[surur_val]+1;
                check[val]=true;
                par[val]=surur_val;
            }
        }
    }

}


int main(){
    int n,e;
    cin >> n  >> e;

    while(e--){
        int a,b;
        cin >> a >> b;

        vi[a].push_back(b);
        vi[b].push_back(a);
    }
    
    int start;
    cin >> start;
    int destination=n;
    cin >> destination;

    memset(level,-1,sizeof(level));
    memset(check,false,sizeof(check));
    memset(par,-1,sizeof(par));

    bfs(1);

    vector<int> rev;

    int i=destination;
    while(i!=-1){

        rev.push_back(i);
        // cout << i << " ";
        i=par[i];
    }

    reverse(rev.begin(),rev.end());

    if(rev.size()<=1) cout << "IMPOSSIBLE" << endl;
    else{
        cout << rev.size() << endl;
        for(int x: rev){
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/* input:

6 5
0 1
2 5
2 4
1 3
3 4
0
5

output:
5
1 3 4 2 5 

*/
