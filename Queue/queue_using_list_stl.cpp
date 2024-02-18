#include <bits/stdc++.h>
using namespace std;

class myQueue{
    public:

    list<int> li;
    void push(int val){
        li.push_back(val);
    }
    void pop(){
        li.pop_front();

    }
    int front(){
        return li.front();
    }
    int size(){
        return li.size();
    }
    bool empty(){
        return li.empty();
    }

};

int main(){
    myQueue q;
    

    int n; cin >> n;
    while(n--){
        int val;
        cin >> val;
        q.push(val);
    }

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}