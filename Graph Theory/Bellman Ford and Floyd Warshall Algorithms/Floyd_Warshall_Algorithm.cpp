#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll v,e;
    cin >> v >> e;

    ll ar[v][v];

    for(int x=0; x<v; x++){
        for(int y=0; y<v; y++){
            ar[x][y]=INT_MAX;
            if(x==y) ar[x][y]=0;
        }
    }                                                            
    while(e--){
        int u,v,c;
        cin >> u >> v >> c;

        ar[u][v]=c;
    }


    cout <<"Bfore: " << endl;
    for(int x=0; x<v; x++){
        for(int y=0; y<v; y++){
            if(ar[x][y]==INT_MAX){
                cout << "INF ";
            }
            else cout << ar[x][y] << " ";
        }
        cout << endl;
    }

    // -------------- main thing ----------- //
    
    for(int z=0; z<v; z++){
        for(int x=0; x<v; x++){
            for(int y=0; y<v; y++){
                
                if(ar[x][z]+ar[z][y] < ar[x][y]){
                    ar[x][y]=ar[x][z]+ar[z][y];
                }
            }
            
        }
    }

    cout<< endl <<"After: " << endl;
    for(int x=0; x<v; x++){
        for(int y=0; y<v; y++){
            if(ar[x][y]==INT_MAX){
                cout << "INF ";
            }
            else cout << ar[x][y] << " ";
        }
        cout << endl;
    }

    // if we want to detect cycle
    bool cycle=false;
    for(int x=0; x<v; x++){
        if(ar[x][x]<0){
            cycle=true;
            break;
        }
    }

    cout << (cycle ? "YES":"NO" )<< endl;
    
    
    return 0;
}

/* input:
4 6
3 2 8
2 1 5
1 0 2
3 0 20
0 1 3
1 2 2

output:
Bfore: 
0 3 INF INF 
2 0 2 INF 
INF 5 0 INF 
20 INF 8 0 

After: 
0 3 5 INF 
2 0 2 INF 
7 5 0 INF 
15 13 8 0 
NO

input:
3 3
0 1 -5
1 2 3
2 0 -1

output: 
Bfore: 
0 -5 INF 
INF 0 3 
-1 INF 0 

After: 
-3 -8 -5 
2 -3 0 
-4 -9 -6 
YES

*/
