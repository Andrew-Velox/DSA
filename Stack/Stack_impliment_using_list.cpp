#include <bits/stdc++.h>
using namespace std;

class myStack{
    public:
        list<int> li;
    
    void push(int val){
        li.push_back(val);
    }
    void pop(){
        li.pop_back();
    }
    int top(){
        return li.back();
    }
    int size(){
        return li.size();
    }
    bool empty(){
        if(li.size()==0) return true;
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

    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}