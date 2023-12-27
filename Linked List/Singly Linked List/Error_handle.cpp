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

void in_at_head(Node *&head, int val){
    Node *newNode= new Node(val); 
    newNode->next=head;       // first point head with new node
    head=newNode;        //  thene update hade to new node
    cout << "\n\nEnserted At Head\n" << endl;
}


void in_at_tail(Node *&head,int val){
    Node *newNode = new Node(val);
    
    if(head==NULL){         // if head Null
        head=newNode; 
        cout << endl << endl << "Inserted At Head\n\n" << endl;
        return;
    }
    Node *tmp = head;       // we cannot change position of head

    while(tmp->next != NULL){      // go until found NULL
        tmp = tmp->next;
    }

    tmp -> next = newNode;          // now the NULL have newNodes Address
    cout << "\n\nEnserted At Tail\n" << endl;

}

void in_at_any_pos(Node *head,int v, int pos){
    Node *newNode = new Node(v);

    Node * tmp= head;
    for(int x=1; x<=pos-1; x++){        // go untill found the position
        tmp=tmp->next;
        if(tmp==NULL){
            cout << "\n\n Invalid Position \n\n";
            return;
        }
    }
    newNode->next=tmp->next; // point newNode nxt to -> tmp nxt node 
    tmp->next=newNode;         // point tmp nxt to newNode

    cout << "\n\nInserted At position " << pos << endl << endl;
}

void delete_Node(Node *&head,int pos){

    if(pos==0){
        if(head==NULL){
            cout << "\n\n There is no Head.\n\n";
            return;
        }
        Node *deleteNode = head;
        head=head->next;
        delete deleteNode;
        cout << "\n\nHead Node Deleted. "<< endl << endl;
        return;
    }
    
    Node *tmp = head;
    for(int x=1; x<=pos-1; x++){    // go for the position
        tmp=tmp->next;
        if(tmp==NULL){
            cout << "\n\n Wrong Position\n\n";
            return;
        }
    }
    if(tmp->next==NULL){
        cout << "\n\n Wrong Position\n\n";
        return;
    }

    Node *deleteNode = tmp->next;       // store delete node
    tmp->next=tmp->next->next;  // connect tmp with 2nd next Node
    delete deleteNode;      // delete That Node
    cout << "\n\nNode Deleted of position " << pos << endl << endl;
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

        cout << "1. Insert at Head." << endl;               // done
        cout << "2. Insert at tail." << endl;               // done 
        cout << "3. Insert at any Position." << endl;       // done
        cout << "4. Delete form Position." << endl;         // done
        cout << "5. Print." << endl;                        // done
        cout << "6. Exit." << endl;                         // done
        cout << "Enter: ";
        int n; cin >> n;

        if(n==1){
            int v;
            cout << "Enter Value: ";
            cin >> v;
            in_at_head(head,v);
        }

        if(n==2){
            int v;
            cout << "Enter Value:";
            cin >> v;
            in_at_tail(head,v);
        }
        else if(n==3){
            cout << "Enter Value: ";
            int v;cin >> v;
            cout << endl << "Enter Position: ";
            int pos; cin >> pos;

            if(pos==0){
                in_at_head(head,v);
            }
            else in_at_any_pos(head,v,pos);
        }

        else if(n==4){
            cout << "Enter Position: ";
            int pos; cin >> pos;

            delete_Node(head,pos);
        }
        else if(n==5){
            print(head);
        }
        else if(n==6){
            break;
        }

    }
    
    return 0;
}