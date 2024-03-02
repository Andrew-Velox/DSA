#include <bits/stdc++.h>
using namespace std;
char ar[40][40];
bool visit[40][40];

int dis[40][40];

vector<pair<int,int>> vals={{0,1},{0,-1},{-1,0},{1,0}};


int r,c;
bool valid(int si,int sj){
    if(si<0 || si>=r || sj<0 || sj>=c) return false;
    else return true;
}


void  bfs(int si, int sj){

    queue<pair<int,int>> q;
    q.push({si,sj});

    visit[si][sj]=true;
    dis[si][sj]=0;

    while(!q.empty()){
        pair<int,int> par=q.front();
        q.pop();

        // cout << par.first << " " << par.second << endl;

        for(int x=0; x<4; x++){
            int xi=par.first+vals[x].first;
            int xj=par.second+vals[x].second;

            if(valid(xi,xj)==true && visit[xi][xj]==false){
                q.push({xi,xj});
                visit[xi][xj]=true;
                dis[xi][xj]=dis[par.first][par.second]+1;
            }
        }
    }


}

int main(){
    cin >> r >> c;

    for(int x=0; x<r; x++){
        for(int y=0; y<c; y++){
            cin >> ar[x][y];
        }
    }

    // start index
    int si,sj;
    cin >> si >> sj;

    memset(visit,false,sizeof(visit));
    memset(dis,-1,sizeof(dis));

    bfs(si,sj);

    cout << dis[2][3] << endl;
    
    return 0;
}

/* input:

3 4
. . . .
. A . .
. . . X
1 1

output:
3

*/
