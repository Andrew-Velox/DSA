#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,e;
    cin >> n >> e;
    int mat[n][n];

    memset(mat,0,sizeof(mat));

    for(int x=0; x<e; x++){
        int a,b;

        cin >> a >> b;

        mat[a][b]=1;
        mat[b][a]=1;  // if we want to make directed graph then we can just remove this

    }

    // check
    // for(int x=0; x<n; x++){
    //     for(int y=0; y<n; y++){
    //         cout << mat[x][y] << " ";
    //     }

    //     cout << endl;
    // }

    // check that is there is any connection or not
    int a,b;
    cin >> a >> b;
    if(mat[a][b]) cout<< "Connected" << endl;
    else cout << "Not Connected" << endl;
    
    // cout << endl;

    return 0;
}