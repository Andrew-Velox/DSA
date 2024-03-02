#include <bits/stdc++.h>
using namespace std;

int r,c;
char ar[100][100];
bool visit[100][100];

vector<pair<int,int>> p = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int xi,int xj){
    if(xi<0 || xi>=r || xj<0 || xj>=c) return false;
    else return true;
}

void dfs(int si,int sj){
    // cout << si << " " << sj << endl;

    visit[si][sj]=true;
    for(int x=0; x<4; x++){
        int xi= si+p[x].first;
        int xj= sj+p[x].second;

        if(valid(xi,xj)==true && visit[xi][xj]==false){
            dfs(xi,xj);
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
    dfs(si,sj);
    
    return 0;
}
