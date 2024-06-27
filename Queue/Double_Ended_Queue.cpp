#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    
    int val;
    Node* next;
    Node* prev;

    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

class myQueue{
    public:

    Node* head=NULL;
    Node* tail = NULL;



    void push_front(int val){
        Node* nn = new Node(val);

        if(head==NULL){
            head=nn;
            tail=nn;
            return;
        }

        head->prev=nn;
        nn->next=head;
        head=head->prev;
    }
    void push_rear(int val){
        Node* nn = new Node(val);

        if(head==NULL){
            head=nn;
            tail=nn;
            return;
        }

        tail->next=nn;
        nn->prev=tail;
        tail=nn;
    }


    void pop_front(){
        cout << endl;
        if(head==NULL){
            cout << "Queue Is Empty\n" << endl;
            return;
        }
        cout << head->val << " Has been Popped\n" <<endl;
        Node* delNode=head;
        head=head->next;
        if(head==NULL){
            tail=NULL;
            delete delNode;
            return;            
        }
        head->prev=NULL;
        delete delNode;
    }
    void pop_rear(){
        cout << endl;
        if(head==NULL){
            cout << "Queue Is Empty\n" << endl;
            return;
        }
        cout << tail->val << " Has been Popped\n" <<endl;
        Node* delNode=tail;
        tail=tail->prev;
        if(tail==NULL){
            head=NULL;
            delete delNode;
            return;
        }
        tail->next=NULL;
        delete delNode;
    }
    void front(){
        cout << endl;
        if(head==NULL){
            cout << "Queue Is Empty\n" << endl;
            return;
        }
        cout << "Front: " << head->val << endl << endl;
    }
    void rear(){
        cout << endl;
        if(head==NULL){
            cout << "Queue Is Empty\n" << endl;
            return;
        }
        cout << "Rear: " << tail->val << endl << endl;
    }
    void print(){
        if(head==NULL){
            cout << "Queue Is Empty\n" << endl;
            return;
        }

        cout << "Values: ";
        Node* tmp = head;

        while(tmp!=NULL){
            cout << tmp->val  << " ";
            tmp=tmp->next;
        }
        cout << endl << endl;
    }
};


int main(){
    myQueue q;

    while(true){
        cout << "1. Push Front" << endl;
        cout << "2. Push Rear" << endl;
        cout << "3. Pop Front" << endl;
        cout << "4. Pop Rear" << endl;
        cout << "5. Print front" << endl;
        cout << "6. Print rear" << endl;
        cout << "7. Print value" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter: " ;

        int opt; cin >> opt;

        if(opt==1){
            cout << endl <<  "Enter Value: ";
            int val; cin >> val;
            q.push_front(val);
        }
        else if(opt==2){
            cout << endl <<  "Enter Value: ";
            int val; cin >> val;
            q.push_rear(val);
        }
        else if(opt==3) q.pop_front();
        else if(opt==4) q.pop_rear();
        else if(opt==5) q.front();
        else if(opt==6) q.rear();
        else if(opt==7){
            cout << endl;
            q.print();
        }
        else if(opt==0) break;
        else cout << "Wrong input" << endl << endl;
    
    }
    return 0;
}