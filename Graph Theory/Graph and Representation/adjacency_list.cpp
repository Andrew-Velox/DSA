#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin >> n >> e;

    vector<int> ar[n];

    while(e--){
        int a,b;
        cin >> a >> b;

        ar[a].push_back(b);
        ar[b].push_back(a);  // if we want to create directed then we dont need this line
    }

    // we use v[i] to access element
    // now we can do ar[n][i]
    // cause ar[n]==v here
    for(int x=0; x<ar[0].size(); x++){
        cout << ar[0][x] << " ";
    }

    cout << endl;

    for(auto x: ar[0]){
        cout << x << " ";
    }

    cout << endl;
    
    return 0;
}