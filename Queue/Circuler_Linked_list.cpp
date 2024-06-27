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

class myQueue{
    public:

    Node* head = NULL;
    Node* tail = NULL;
    int sz=0;



    void push(int val){
        Node* nn = new Node(val);
        if(head==NULL){
            head=nn;
            tail=nn;
            tail->next=head;
            return;
        }
        tail->next=nn;
        tail=tail->next;
        tail->next=head;
    }

    void pop(){
        cout << endl;
        if(head==NULL){
            cout << "Queue Is Empty\n" << endl;
            return;
        }
        cout << head->val << " Has been Poped\n" <<endl;
        Node* delNode=head;
        head=head->next;
        tail->next=head;
        delete delNode;
        if(head==NULL) tail=NULL;
    }

    void front(){
        cout << endl;
        if(head==NULL){
            cout << "Queue Is Empty\n" << endl;
            return;
        }
        cout << "Front: " << head->val << endl << endl;
    }

    void print(){
        cout << endl;
        if(head==NULL){
            cout << "Queue Is Empty\n" << endl;
            return;
        }

        cout << "Values: ";
        Node* tmp = head;

        while(1){
            cout << tmp->val  << " ";
            tmp=tmp->next;
            if(tmp==head) break;
        }
        cout << endl << endl;
    }
};

int main(){
    myQueue q;

    while(true){
        cout << "1. Push value" << endl;
        cout << "2. Pop value" << endl;
        cout << "3. Print front" << endl;
        cout << "4. Print value" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter: " ;

        int opt; cin >> opt;

        if(opt==1){
            cout << endl <<  "Enter Value: ";
            int val; cin >> val;
            q.push(val);
        }
        else if(opt==2) q.pop();
        else if(opt==3) q.front();
        else if(opt==4){
            cout << endl;
            q.print();
        }
        else if(opt==0) break;
        else cout << "Wrong input" << endl << endl;
    
    }
    return 0;
}