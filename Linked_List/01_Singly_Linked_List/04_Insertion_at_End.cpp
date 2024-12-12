#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    //CONSTRUCTOR
    Node(int data){
        this->data = data;
        this->next=NULL;
    }
};

//INSERTION AT BEGINNING / START / HEAD
void insertAtStart(Node* &head, Node*&tail, int data){
    Node *newNode = new Node(data);
    //if LL is empty
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

// INSERTION AT LAST / END / TAIL
void insertAtEnd(Node*&head, Node*&tail, int data){
    Node *newNode = new Node(data);
    //if LL is empty
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

// TRAVERSAL OF LINKED LIST
void traverse(Node*&head){
    //if LL is empty
    if(head == NULL){
        cout << "Linked List is empty" << endl;
        return;
    }
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main(){
    
    // //CREATING HEAD AND TAIL POINTERS
    Node *head = NULL;
    Node *tail = NULL;
    
    //insertion operation
    insertAtStart(head, tail, 20);         //at start
    traverse(head);
    insertAtEnd(head, tail, 7);            //at end
    traverse(head);
    insertAtEnd(head, tail, 44);           //at end
    traverse(head);
    insertAtStart(head, tail, 13);         //at start
    traverse(head);
    cout << "HEAD - " << head->data << endl;
    cout << "TAIL - " << tail->data << endl;
}
