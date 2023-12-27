#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *next;

    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

void in_at_tail(Node *&head,Node *&tail,int val){               //  O(1)
    Node *newNode = new Node(val);

    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }

    // Node*tmp=head;                   // O(n)
    // while(tmp->next!=NULL){
    //     tmp=tmp->next;
    // }
    // tmp->next=newNode;
    
    tail->next=newNode;                 // O(1)
    tail=newNode;
}

void print(Node *head){
    Node *tmp = head;
    cout << endl << "Linked List: ";
    while(tmp!=NULL){
        cout << tmp->val << " ";
        tmp= tmp->next;
    }
    cout << endl << endl;
}


void solve(){
    Node *head=NULL;    
    Node *tail=NULL;

    int val;
    while(1){
        cin >> val;
        if(val==-1) break;
        in_at_tail(head,tail,val);
    }
    print(head);
    
}

int main(){
    long long int t=1;// cin >> t;
    while(t--) solve();
    return 0;
}