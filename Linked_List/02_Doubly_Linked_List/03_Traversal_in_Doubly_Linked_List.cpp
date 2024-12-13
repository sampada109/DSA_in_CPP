// TRAVERSING THROUGH THE DOUBLY LINKED LIST

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;          // pointer of type Node, pointing to the previous node
    Node *next;          // pointer of type Node, pointing to the next node
    
    //CONSTRUCTOR
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

// TRAVERSAL THROUGH DOUBLY LINKED LIST
void traverse(Node* &head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// INSERTION AT BEGINNING/START/HEAD
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
    traverse(head);
    insertAtStart(head, tail, 3);
    traverse(head);
    insertAtStart(head, tail, 12);
    traverse(head);
    
    // CHECKING WHICH DATA HEAD AND TAIL POINTING
    cout << "HEAD - " << head->data << endl;
    cout << "TAIL - " << tail->data << endl;

}
