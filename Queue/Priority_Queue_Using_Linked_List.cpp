#include <bits/stdc++.h>
using namespace std;

class Node{
    public:

    int val;
    int priority;
    Node* next;

    Node(int val,int priority){
        this->val=val;
        this->priority=priority;
        this->next=NULL;
    }
};

class myPriority_Queue{
    public:

    Node* head= NULL;
    Node* tail= NULL;

    void push(int val, int prio){
        Node* nn = new Node(val,prio);

        if(head==NULL){
            head=nn;
            tail=nn;
            return;
        }
        else if(nn->priority < head->priority){
            nn->next=head;
            head=nn;
        }
        else{
            Node* tmp = head;

            while(tmp->next!=NULL && tmp->next->priority < nn->priority){
                tmp=tmp->next;
            }
            nn->next=tmp->next;
            tmp->next=nn;
        }

    }

    void pop(){
        cout << endl;

        if(head==NULL){
            cout << "Priority Queue Is empty\n" << endl;
            return;
        }
        cout << head->val << " Has been Poped\n" <<endl;
        Node* delNode = head;
        head=head->next;
        delete delNode;
        if(head==NULL) tail=NULL;
        
    }

    void front(){
        cout << endl;

        if(head==NULL){
            cout << "Priority Queue Is empty\n" << endl;
            return;
        }
        cout << "Front: " <<  head->val << endl << endl;
    }

    void print(){
        if(head==NULL){
            cout << "Priority Queue Is empty\n" << endl;
            return;
        }
        cout << "Values: ";
        Node* tmp = head;

        while(tmp!=NULL){
            cout << tmp->val << " ";
            tmp = tmp->next;
        }

        cout << endl << endl;
    }

};


int main(){
    myPriority_Queue pq;

    while(true){
        cout << "1. Push value" << endl;
        cout << "2. Pop value" << endl;
        cout << "3. Print front" << endl;
        cout << "4. Print values" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter: " ;

        int opt; cin >> opt;

        if(opt==1){
            cout << endl <<  "Enter Value: ";
            int val; cin >> val;
            cout <<"Enter Priority: ";
            int prio; cin >> prio;
            pq.push(val,prio);

            cout << endl;
            pq.print();
        }
        else if(opt==2) pq.pop();
        else if(opt==3) pq.front();
        else if(opt==4){
            cout << endl;
            pq.print();
        }
        else if(opt==0) break;
        else cout << "Wrong input" << endl << endl;
    
    }
    return 0;
}