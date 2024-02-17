#include <bits/stdc++.h>
using namespace std;

int main(){

    stack<int> st;

    int n; cin >> n;

    for(int x=0; x<n; x++){
        int v; cin >> v;
        st.push(v);
    }

    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}