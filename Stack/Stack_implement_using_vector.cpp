#include <bits/stdc++.h>
using namespace std;

class myStack{
    public:
        vector<int> vi;
    
    void push(int val){
        vi.push_back(val);
    }
    void pop(){
        vi.pop_back();
    }
    int top(){
        return vi.back();
    }
    int size(){
        return vi.size();
    }
    bool empty(){
        if(vi.size()==0) return true;
        else return false;
    }
};

int main(){

    myStack st;

    
    int n; cin >> n;

    for(int x=0; x<n; x++){
        int v; cin >> v;
        st.push(v);
    }

    while(st.empty()==false){
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}
