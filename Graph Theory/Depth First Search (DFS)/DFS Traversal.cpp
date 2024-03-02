#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> vi[N];
bool visit[N];

void dfs(int str){

    //ja korar ekhane
    cout << str << " ";

    // onno kaj
    visit[str]=true;
    for(int val: vi[str]){
        if(visit[val]== false){
            dfs(val);
        }
    }
}

int main(){
    int v,e;
    cin >> v >> e;

    while(e--){
        int a,b;
        cin >> a >> b;

        vi[a].push_back(b);
        vi[b].push_back(a);
    }
    int str; cin >> str;

    dfs(str);


    return 0;
}

/* 
input:

6 6
0 1
1 2
2 5
2 4
1 3
3 4
0

output:
0 1 2 5 4 3 


*/
