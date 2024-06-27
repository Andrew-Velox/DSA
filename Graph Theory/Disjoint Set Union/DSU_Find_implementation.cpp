#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int> vi;

void intlz(int n){
    for(int x=0; x<=n; x++) vi.push_back(-1);

    vi[2]=1;
    vi[1]=3;

}

int find(int val){
    if(vi[val]==-1) return val;

    return vi[val]=find(vi[val]);
}


int main(){
    intlz(3);   
 
    cout << find(0) << endl;
    cout << find(1) << endl;
    cout << find(2) << endl;
    cout << find(3) << endl;
    
    
    return 0;
}