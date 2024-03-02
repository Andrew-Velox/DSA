#include <bits/stdc++.h>
using namespace std;
vector<int> vi[10005];
bool check[10005];

int level[10005];

void bfs(int st){
    queue<int> q;
    q.push(st);

    check[st]=true;
    level[st]=0;
    
    while(!q.empty()){
        int surur_val=q.front();
        q.pop();

        // cout << surur_val << endl;


        for(int val: vi[surur_val]){
            if(!check[val]){
                q.push(val);
                level[val]=level[surur_val]+1;
                check[val]=true;
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

    memset(level,-1,sizeof(level));
    memset(check,false,sizeof(check));

    bfs(start);

    for(int x=0; x<n; x++){
        cout << x << " ar level-> " << level[x] << endl;
    }

    cout << endl;
    
    
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

0 ar level-> 0
1 ar level-> 1
2 ar level-> 2
3 ar level-> 2
4 ar level-> 3
5 ar level-> 3


*/
