// REVERSEING LINKED LIST **NODE**
// FOR REVERSNG THE LINKED LIST NODES, POINTER APPROCH IS USED

#include<bits/stdc++.h>
using namespace std;

// NODE STRUCTURE
class Node{
    public:
    int data;
    Node *next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// TRAVERSAL
void traverse(Node *&head){
    // IF LINKED IS EMPTY
    if(head == NULL){
        return;
    }
    Node *temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// INSERTION AT END
void insert_node(Node* &head, Node*&tail, int data){
    Node *newNode = new Node(data);
    // IF LL IS EMPTY
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

// REVERSE A LINKED LIST
Node* reverse(Node* &head){
    // POINTER APPROCH
    Node *prevNode = NULL;
    Node *curNode = head;
    Node *nextNode = NULL;
    
    while(curNode){
        nextNode = curNode->next;    // POINTS TO NEXT NODE
        curNode->next = prevNode;    // CURRENT NODE POINTS TO PREVIOUS NODE
        prevNode = curNode;
        curNode = nextNode;
    }
    
    return prevNode;
}

int main(){
    // INITIALISING AN ARRAY
    vector<int> arr = {1,2,3,4,5};
    
    // INITIALISING HEAD POINTER AND TAIL POINTER
    Node *head = NULL;
    Node *tail = NULL;
    
    // INSERT ARRAY ELEMENT IN LINKED LIST
    for(int i=0; i<arr.size(); i++){
        insert_node(head, tail, arr[i]);
    }
    
    traverse(head);
    
    head = reverse(head);
    
    traverse(head);
    
}
