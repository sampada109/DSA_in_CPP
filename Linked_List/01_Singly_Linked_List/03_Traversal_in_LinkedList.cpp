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
    insertAtStart(head, tail, 34);         //at start
    traverse(head);
    insertAtStart(head, tail, 1);         //at start
    traverse(head);
    insertAtStart(head, tail, 3);         //at start
    traverse(head);
    insertAtStart(head, tail, 15);         //at start
    traverse(head);

}
