#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *next;
        Node *prev;

    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
void print_nrml(Node *head){
    Node *tmp=head;

    while(tmp!=NULL){
        cout << tmp->val << " ";
        tmp=tmp->next;
    }
    cout << endl;

}

void print_rev(Node *tail){
    Node *tmp=tail;

    while(tmp!=NULL){
        cout << tmp->val << " ";
        tmp=tmp->prev;
    }
    cout << endl;

}

void solve(){
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *tail = b;
    
    head->next=a;
    a->prev=head;
    a->next=b;
    b->prev=a;

    print_nrml(head);
    print_rev(tail);

    
}

int main(){
    long long int t=1;// cin >> t;
    while(t--) solve();
    return 0;
}