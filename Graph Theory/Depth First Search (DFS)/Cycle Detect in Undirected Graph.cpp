#include <bits/stdc++.h>
using namespace std;
const int N= 1e5+10;

vector<int> ar[N];

int parentArray[N];
bool visit[N];


bool check=false;

void dfs(int st){
    visit[st]=true;

    for(int x: ar[st]){

        if(visit[x]==true && parentArray[st]!=x){
            check=true;
        }

        if(visit[x]==false){
            parentArray[x]=st;
            dfs(x);
            
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
            dfs(x);
        }
    }



    if(check) cout << "Cycle Detected" << endl;
    else cout << "Not Detected" << endl;
    return 0;
}
