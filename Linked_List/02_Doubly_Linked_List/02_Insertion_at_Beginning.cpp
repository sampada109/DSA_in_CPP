// INSERTING NODE AT STARTING POSITION IN DOUBLY LINKED LIST

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;           // pointer of type Node, pointing to the previous node
    Node *next;           // pointer of type Node, pointing to the next node
    
    //CONSTRUCTOR
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtStart(Node* &head, Node* &tail, int data){
    //CREATE NODE
    Node *newNode = new Node(data);
    
    //IF LL IS EMPTY
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{    //LL HAVE ONE OR MORE NODES PRESENT
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

int main(){
    // CREATING HEAD AND TAIL POINTER
    Node *head = NULL;
    Node *tail = NULL;
    
    // INSERTION
    insertAtStart(head, tail, 10);
    insertAtStart(head, tail, 3);
    insertAtStart(head, tail, 12);
    
    // CHECKING WHICH DATA HEAD AND TAIL POINTING
    cout << "HEAD - " << head->data << endl;
    cout << "TAIL - " << tail->data << endl;
}
