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

void in_at_head(Node *&head,Node *&tail,int val){

    Node *newNode = new Node(val);

    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }

    newNode->next=head;
    head->prev=newNode;
    head = newNode;
}

void in_at_tail(Node *&head, Node *&tail, int val){
    Node *newNode=new Node(val);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
}

void in_at_any_pos(Node *&head,int pos, int val){
    Node *newNode=new Node(val);
    
    Node *tmp=head;
    for(int x=1;x<=pos-1; x++){
        tmp=tmp->next;
    }

    newNode->next=tmp->next;    // 100->30
    tmp->next->prev=newNode;    // 30<-100
    tmp->next=newNode;          // 20-> 100
    newNode->prev=tmp;          // 100<-20

}

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

int size(Node *head){
    Node *tmp=head;

    int cnt=0;
    while(tmp!=NULL){
        cnt++;
        tmp=tmp->next;
    }
    return cnt;
}

void solve(){
    Node *head = NULL;
    Node *tail = NULL;
    // Node *head = new Node(10);
    // Node *a = new Node(20);
    // Node *b = new Node(30);
    // Node *c = new Node(40);
    // Node *tail = c;
    
    // head->next=a;
    // a->prev=head;
    // a->next=b;
    // b->prev=a;
    // b->next=c;
    // c->prev=b;

    int pos,val;
    // cin >> pos >> val;

    in_at_tail(head,tail,100);

    print_nrml(head);
    print_rev(tail);

    // if(pos==0){
    //     in_at_head(head,tail,val);
    // }
    // else if(pos>size(head)){
    //     cout << "Invalid" << endl;
    // }
    // else if(pos==size(head)){
    //     in_at_tail(head,tail,val);
    // }
    // else{
    //     in_at_any_pos(head,pos,val);
    // }
    // in_at_any_pos(head,,100);
    // in_at_head(head,100);
    // in_at_head(head,150);

    print_nrml(head);
    print_rev(tail);
    
}

int main(){
    long long int t=1;// cin >> t;
    while(t--) solve();
    return 0;
}