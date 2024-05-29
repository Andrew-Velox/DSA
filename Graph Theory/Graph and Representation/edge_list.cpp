#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin >> n >> e;
    vector<pair<int,int>> v;

    while(e--){
        int a,b;
        cin >> a >> b;

        v.push_back({a,b});
    }

    // for(int x=0; x<v.size(); x++){
    //     cout << v[x].first << " " << v[x].second << endl;
    // }

    // cout << endl;

    for(pair<int,int>/* auto */ x: v){
        cout << x.first << " " << x.second << endl;
    }
    
    return 0;
}