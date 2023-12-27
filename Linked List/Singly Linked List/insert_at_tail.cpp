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

void in_at_tail(Node *&head,int val){
    Node *newNode = new Node(val);
    
    if(head==NULL){
        head=newNode;
        return;
    }
    Node *tmp = head;

    while(tmp->next != NULL){
        tmp = tmp->next;
    }

    tmp -> next = newNode;

}

void print(Node *head){
    Node *tmp = head;
    while(tmp!=NULL){
        cout << tmp->val << " ";
        tmp= tmp->next;
    }
}

int main(){
    Node *head = NULL;
    cout << "1. Insert at tail." << endl;
    int n; cin >> n;

    if(n==1){
        int v; cin >> v;
        in_at_tail(head,v);
    }

    print(head);
    return 0;
}