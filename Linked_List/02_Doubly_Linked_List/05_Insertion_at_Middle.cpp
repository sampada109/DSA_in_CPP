// INSERTION OF NODE AT ANY SPECIFIED POSITION IN DOUBLY LINKED LIST

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


int main(){
    // CREATING HEAD AND TAIL POINTER
    Node *head = NULL;
    Node *tail = NULL;
    
    // INSERTION
    insertAtEnd(head, tail, 10);              //insertion at end
    traverse(head);
    insertAtStart(head, tail, 3);             //insertion at start
    traverse(head);
    insertAtEnd(head, tail, 12);              //insertion at end
    traverse(head);
    insertAtMiddle(head, tail, 33, 1);        //insertion in middle at position 1
    traverse(head);
    insertAtMiddle(head, tail, 18, 2);        //insertion in middle at position 2
    traverse(head);
    insertAtMiddle(head, tail, 34, 9);        //insertion in middle at position 9
    traverse(head);
    
    // CHECKING WHICH DATA HEAD AND TAIL POINTING
    cout << "HEAD - " << head->data << endl;
    cout << "TAIL - " << tail->data << endl;

}
