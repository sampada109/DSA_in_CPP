// ALL OPERATIONS IN DOUBLY LINKED LIST

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
    // IF LL IS EMPTY
    if(head == NULL){
        cout << "Linked List is Empty" << endl;
        return;
    }
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

// INSERTION AT LAST/END/TAIL
void insertAtEnd(Node* &head, Node* &tail, int data){
    //CREATE NODE
    Node *newNode = new Node(data);
    
    //IF LL IS EMPTY
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{    //LL HAVE ONE OR MORE NODES PRESENT
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// INSERTION AT MIDDLE (positions can be 1st, last, any mid)
void insertAtMiddle(Node* &head, Node* &tail, int data, int position){
    //CREATE NODE
    Node *newNode = new Node(data);
    
    // IF STARTING POSITION
    if(position == 1){
        insertAtStart(head, tail, data);
        return;
    }
    
    Node *temp = head;
    int cnt = 1;
    while(temp != NULL && cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    
    // IF POSITION OUT OF RANGE
    if(temp == NULL){
        cout << "Position Out of Linked List" << endl;
        return;
    }
    
    // IF LAST NODE IS REACHED
    if(temp->next == NULL){
        insertAtEnd(head, tail, data);
        return;
    }
    
    // ANY MIDDLE POSITION
    Node *curTemp = temp->next; 
    newNode->next = curTemp;
    curTemp->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}


// DELETION OF NODE COVERS ALL CASES
void deleteNode(Node*&head, Node*&tail, int position){
    // LL IS EMPTY
    if(head == NULL){
        cout << "Linked List is Empty" << endl;
        return;
    }
    
    // IF ONLY ONE NODE EXISTS
    if(head->next == NULL){
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    
    // NOW MORE THAN ONE NODE EXISTS IN LL
    
    // IF STARTING POSITION
    if(position == 1){
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }
    
    // OTHER THAN STARTING POSITION
    Node *cur = head;
    Node *prv = NULL;
    int cnt = 1;
    while(cur != NULL && cnt<position){
        prv = cur;
        cur = cur->next;
        cnt++;
    }
    
    // IF POSITION IS OUT OF RANGE
    if(cur == NULL){
        cout << "Position out of Range" << endl;
        return;
    }
    
    // IF LAST POSITION
    if(cur->next == NULL){
        prv->next = NULL;
        tail = prv;
    }
    else{  // IF IT IS ANY MIDDLE POSITION
        Node *curNext = cur->next;
        prv->next = cur->next;
        curNext->prev = cur->prev;
    }
    
    // CLEAN UP THE CURRENT NODE
    cur->next = NULL;
    cur->prev = NULL;
    delete cur;

}


int main(){
    // CREATING HEAD AND TAIL POINTER
    Node *head = NULL;
    Node *tail = NULL;
    
    // INSERTION
    insertAtEnd(head, tail, 10);        //insertion at end
    traverse(head);
    insertAtEnd(head, tail, 12);        //insertion at end
    traverse(head);
    insertAtStart(head, tail, 5);       //insertion at start
    traverse(head);
    insertAtMiddle(head, tail, 7, 3);   //insertion in middle at position 3
    traverse(head);
    insertAtMiddle(head, tail, 33, 1);   //insertion in middle at position 1
    traverse(head);
    
    // DELETION
    deleteNode(head, tail, 1);       //deletion from position 1
    traverse(head);
    deleteNode(head, tail, 4);       //deletion from position 4
    traverse(head);
    deleteNode(head, tail, 2);       //deletion from 2
    traverse(head);
    deleteNode(head, tail, 1);       //deletion from 1
    traverse(head);
    
    // CHECKING WHICH DATA HEAD AND TAIL POINTING
    head == NULL ? cout << "HEAD - " << 0 << endl : cout << "HEAD - " << head->data << endl;
    tail == NULL ? cout << "TAIL - " << 0 << endl : cout << "TAIL - " << tail->data << endl;
  
}
