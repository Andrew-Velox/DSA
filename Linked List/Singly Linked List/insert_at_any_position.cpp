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
        cout << endl << endl << "Inserted At Head\n\n" << endl;
        return;
    }
    Node *tmp = head;

    while(tmp->next != NULL){
        tmp = tmp->next;
    }

    tmp -> next = newNode;
    cout << "\n\nEnserted At Tail\n" << endl;

}

void in_at_any_pos(Node *head,int v, int pos){
    Node *newNode = new Node(v);

    Node * tmp= head;
    for(int x=1; x<=pos-1; x++){
        tmp=tmp->next;
    }
    newNode->next=tmp->next;
    tmp->next=newNode;

    cout << "\n\nInserted At position " << pos << endl << endl;
}

void print(Node *head){
    Node *tmp = head;
    cout << endl << endl << "Your Linked List: ";
    while(tmp!=NULL){
        cout << tmp->val << " ";
        tmp= tmp->next;
    }
    cout << endl << endl;
}



int main(){
       
    Node *head = NULL;
    while(1){

        cout << "1. Insert at tail." << endl;
        cout << "2. Insert at any Position." << endl;
        cout << "3. Print." << endl;
        cout << "4. Exit." << endl;
        cout << "Enter: ";
        int n; cin >> n;

        if(n==1){
            int v;
            cout << "Enter Value:";
            cin >> v;
            in_at_tail(head,v);
        }
        else if(n==2){
            cout << "Enter Value: ";
            int v;cin >> v;
            cout << endl << "Enter Position: ";
            int pos; cin >> pos;
            in_at_any_pos(head,v,pos);
        }
        else if(n==3){
            print(head);
        }
        else if(n==4){
            break;
        }

    }
    return 0;
}