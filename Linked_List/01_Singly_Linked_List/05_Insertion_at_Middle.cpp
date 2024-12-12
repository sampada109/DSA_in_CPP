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

// INSERTION AT BEGINNING / START / HEAD
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

// INSERTION AT END / LAST / TAIL
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

// INSERTION IN MIDDLE ( positions can be beginning, end, mid)
void inserAtMiddle(Node*&head, Node*&tail, int data, int position){
    // creating a new node
    Node *newNode = new Node(data);
  
    //checking if position is 1 i.e insert at start;
    if(position == 1){
        insertAtStart(head, tail, data);
        return;
    }

    // other than starting position
    Node *temp = head;
    int cnt = 1;
    while(cnt < position){
        temp = temp->next;
        cnt++;
    }
  
    //if position is last
    if(temp == NULL){
        insertAtEnd(head, tail, data);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// TRAVERSAL IN LINKED LIST
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
    inserAtMiddle(head, tail, 3, 1);       //at middle
    traverse(head);
    inserAtMiddle(head, tail, 13, 3);      //at middle
    traverse(head);
    insertAtEnd(head, tail, 7);            //at end
    traverse(head);
    insertAtEnd(head, tail, 44);           //at end
    traverse(head);
    inserAtMiddle(head, tail, 67, 2);      //at middle
    traverse(head);
    cout << "HEAD - " << head->data << endl;
    cout << "TAIL - " << tail->data << endl;

}
